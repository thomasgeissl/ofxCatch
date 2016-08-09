#include "ofMain.h"
#define CATCH_CONFIG_RUNNER
#include "ofxCatch.h"
#include "ofApp.h"


TEST_CASE( "error", "[error]" ) {
    ofApp *app = new ofApp();
    SECTION( "error-add", "[add]" ) {
        REQUIRE( app->add(0,1)  == 1 );
        REQUIRE( app->add(1,1)  == 1 );
    }
}

TEST_CASE( "success", "[success]" ) {
    ofApp *app = new ofApp();
    SECTION( "success-add", "[add]" ) {
        REQUIRE( app->add(0,1)  == 1 );
        REQUIRE( app->add(1,1)  == 2 );
    }
}

TEST_CASE( "default", "[default]" ) {
    ofSetupOpenGL(1024,768, OF_WINDOW);
    ofRunApp(new ofApp());
}

int main( int argc, char* const argv[] )
{
  Catch::Session session; // There must be exactly once instance

  // writing to session.configData() here sets defaults
  // this is the preferred way to set them

  int returnCode = session.applyCommandLine( argc, argv );
  if( returnCode != 0 ) // Indicates a command line error
    return returnCode;

  // writing to session.configData() or session.Config() here 
  // overrides command line args
  // only do this if you know you need to

  return session.run();
}
