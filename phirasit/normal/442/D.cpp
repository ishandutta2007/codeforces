#include <iostream>
#include <set>

const int N = 1000010;

int value[ N ], p[ N ];
std::pair< int, int > mx1[ N ], mx2[ N ];
int n;

void fix( int u, int v ) {
    if ( mx1[u].second == v ) {
        mx1[u].first = value[v];
    } else if ( mx2[u].second == v ) {
        if ( mx2[u].first == mx1[u].first ) {
            std::swap( mx2[u], mx1[u] );
            mx1[u].first = value[v];
        } else {
            mx2[u].first = value[v];
        }
    } else if ( value[v] > mx1[u].first ) {
        mx2[u] = mx1[u];
        mx1[u] = { value[v], v };
    } else if ( value[v] > mx2[u].first ) {
        mx2[u] = { value[v], v };
    }
    int nw_value = mx1[u].first;
    nw_value = std::max( nw_value, mx2[u].first + ( u != 1 ) );

    if ( nw_value > value[u] ) {
        // std::cout << "fix : " << u << " " << v << ":  " << nw_value << std::endl;
        value[u] = nw_value;
        if ( u != 1 ) {
            fix( p[u], u );
        }
    }
}

int main( void ) {

    std::cin.sync_with_stdio( false );
    std::cin.tie( 0 );

    std::cin >> n;
    for ( int i = 2 ; i <= n+1 ; ++i ) {
        std::cin >> p[i];

        value[ i ] = 1;
        fix( p[i], i );
        std::cout << value[1] << " ";
    }

    std::cout << std::endl;

    return 0;
}