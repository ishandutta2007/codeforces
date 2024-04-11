#include <iostream>
#include <vector>

using namespace std;

const int N = 5e2 + 10;

long long dp[ N ][ N ];

long long A[ N ], B[ N ];
int n, m;

vector< pair< int, char > > ans;

void solve( int a, int b ) {
    if ( a >= b ) return;

    for ( int i = a ; i < b ; ++i ) {
        if ( dp[ a ][ i ] == -1 ) continue;
        if ( dp[ i+1 ][ b ] == -1 ) continue;
        if ( dp[ a ][ i ] != dp[ i+1 ][ b ] ) {
            solve( i+1, b );
            solve( a, i );
            if ( dp[ a ][ i ] > dp[ i+1 ][ b ] ) {
                ans.push_back( { a, 'R' } );
            } else {
                ans.push_back( { a+1, 'L' } );
            }
            break;
        }
    }
}
int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    cin >> n;
    for ( int i = 1 ; i <= n ; ++i ) {
        cin >> A[ i ];
    }
    cin >> m;
    for ( int i = 1 ; i <= m ; ++i ) {
        cin >> B[ i ];
    }

    for ( int i = n ; i > 0 ; --i ) {
        for ( int j = i ; j <= n ; ++j ) {
            if ( i == j ) {
                dp[ i ][ j ] = A[ i ];
            } else {
                dp[ i ][ j ] = -1;
                for ( int k = i ; k < j ; ++k ) {
                    if ( dp[ i ][ k ] == -1 ) continue;
                    if ( dp[ k+1 ][ j ] == -1 ) continue;
                    if ( dp[ i ][ k ] != dp[ k+1 ][ j ] ) {
                        dp[ i ][ j ] = dp[ i ][ k ] + dp[ k+1 ][ j ];
                        break;
                    }
                }
            }
        }
    }

    int idx = n, cnt = m;
    for ( int i = n ; i >= 1 ; --i ) {
        if ( cnt > 0 and dp[ i ][ idx ] == B[ cnt ] ) {
            solve( i, idx );
            idx = i - 1;
            --cnt;
        }
    }

    if ( idx > 0 or cnt > 0 ) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for ( const auto p : ans ) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}