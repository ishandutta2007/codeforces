#include <cstdlib>
#include <iostream>

using namespace std;

void error(void ) {
    cout << "NO" << endl;
    exit(0);
}
int main( void ) {

    int n;
    cin >> n;

    int pos = 20000;
    for ( int i = 0 ; i < n ; ++i ) {
        int t;
        string dir;
        cin >> t >> dir;

        if ( dir == "South" ) {
            if ( pos < t ) {
                error();
            }
            pos -= t;
        } else if ( dir == "North" ) {
            if ( pos + t > 20000 ) {
                error();
            }
            pos += t;
        } else {
            if ( pos == 0 or pos == 20000 ) {
                error();
            }
        }
    }

    if ( pos != 20000 ) error();

    cout << "YES" << endl;
    return 0;
}