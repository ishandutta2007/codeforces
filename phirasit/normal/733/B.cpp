#include <iostream>

using namespace std;

int val[ (int) 1e5 + 10 ];
int n;

int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    cin >> n;

    int ans = 0;
    for ( int i = 1 ; i <= n ; ++i ) {
        int l, r;
        cin >> l >> r;
        ans += ( val[i] = l - r );
    }

    int idx = 0, best = abs( ans );
    for ( int i = 1 ; i <= n ; ++i ) {
        if ( abs( ans - 2 * val[i] ) > best ) {
            best = abs( ans - 2 * val[i] );
            idx = i;
        }
    }

    cout << idx << endl;

    return 0;
}