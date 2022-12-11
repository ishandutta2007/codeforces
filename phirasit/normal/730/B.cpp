#include <iostream>

using namespace std;

int checkMn( int a, int b ) {
    if ( a == -1 ) return b;
    cout << "?" << " " << a << " " << b << endl;
    string res;
    cin >> res;
    return res == "<" ? a : b;
}
int checkMx( int a, int b ) {
    if ( a == -1 ) return b;
    cout << "?" << " " << a << " " << b << endl;
    string res;
    cin >> res;
    return res == ">" ? a : b;
}
int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    int test;
    cin >> test;
    while ( test-- ) {
        int n;
        cin >> n;

        int mx = -1, mn = -1;
        for ( int i = 1 ; i <= n ; i += 2 ) {
            if ( i + 1 <= n ) {
                if ( checkMn( i, i+1 ) == i ) {
                    mn = checkMn( mn, i );
                    mx = checkMx( mx, i+1 );
                } else {
                    mn = checkMn( mn, i+1 );
                    mx = checkMx( mx, i );
                }
            } else {
                mn = checkMn( mn, i );
                mx = checkMx( mx, i );
            }
        }

        cout << "!" << " " << mn << " " << mx << endl;
    }
    return 0;
}