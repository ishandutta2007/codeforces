#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>

const int N = 1e5 + 10;

class Edge {
public:
    int u, v, l;
    int next( int x ) {
        return u xor v xor x;
    }
    void read( void ) {
        std::cin >> u >> v >> l;
    }
} edge[ N ];

int subtree[ N ];
std::vector< int > adj[ N ];
int n, m;

inline double choose( long long n );
void dfs_init( int u, int par );

int main( void ) {

    std::cin.sync_with_stdio( false );
    std::cin.tie( 0 );

    std::cin >> n;
    for ( int i = 1 ; i < n ; ++i ) {
        edge[i].read();
        adj[ edge[i].u ].emplace_back( i );
        adj[ edge[i].v ].emplace_back( i );
    }

    const double total = ( long long ) n * ( n-1 ) * ( n-2 ) / 6;

    dfs_init( 1, -1 );

    double ans = 0.0;
    for ( int i = 1 ; i < n ; ++i ) {
        const double size1 = std::min( subtree[ edge[i].u ], subtree[ edge[i].v ] );
        const double size2 = n - size1;
        double group = size1 * size2 * ( n - 2ll );
        ans += edge[ i ].l * group / total;
    }

    std::cout << std::setprecision( 8 ) << std::fixed;

    std::cin >> m;
    for ( int i = 0 ; i < m ; ++i ) {
        int id, new_len;
        std::cin >> id >> new_len;

        const double size1 = std::min( subtree[ edge[id].u ], subtree[ edge[id].v ] );
        const double size2 = n - size1;
        double group = size1 * size2 * ( n - 2ll );
        const double gap = edge[ id ].l - new_len;
        ans -= gap * group / total;

        edge[ id ].l = new_len;
        printf("%.8lf\n", ans );
    }

    return 0;
}

inline double choose( long long n ) {
    return (double) ( n * ( n-1 ) / 2ll );
}
void dfs_init( int u, int par ) {
    subtree[ u ] = 1;
    for ( int id : adj[ u ] ) {
        int v = edge[ id ].next( u );
        if ( v == par ) continue;
        dfs_init( v, u );
        subtree[ u ] += subtree[ v ];
    }
}