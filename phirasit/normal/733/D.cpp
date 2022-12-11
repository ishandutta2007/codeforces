#include <iostream>
#include <map>

using namespace std;

typedef pair< int, int > pii;

map< pii, pii > mp;

int ans = 0, idx1 = -1, idx2 = -1;
int n;

int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    cin >> n;
    for ( int i = 1 ; i <= n ; ++i ) {
        int a, b, c;
        cin >> a >> b >> c;

        if ( a > b ) swap( a, b );
        if ( b > c ) swap( b, c );
        if ( a > b ) swap( a, b );

        if ( a > ans ) {
            ans = a;
            idx1 = i;
            idx2 = -1;
        }

        if ( mp.find( { b, c } ) == mp.end() ) {
            mp[ { b, c } ] = { a, i };
        } else {
            auto it = mp.find( { b, c } );
            int val = min( b, it->second.first + a );
            if ( val > ans ) {
                ans = val;
                idx1 = it->second.second;
                idx2 = i;
            }
            if ( a > it->second.first ) {
                it->second = { a, i };
            }
        }
    }

    cout << 1 + ( idx2 != -1 ) << endl;
    cout << idx1;
    if ( idx2 != -1 ) cout << " " << idx2;
    cout << endl;

    return 0;
}