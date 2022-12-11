#include <iostream>
#include <vector>

using namespace std;

const int N = 1010;

vector< int > data;
vector<int> adj[ N ];
long long dp[ N ];
int w[ N ], b[ N ], pass[ N ];
int n, m, W;

void dfs( int u ) {
    if ( pass[u] ) return;
    pass[u] = 1;
    data.emplace_back(u);
    for ( int v : adj[u] ) {
        dfs( v );
    }
}
int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    cin >> n >> m >> W;
    for (int i = 1 ; i <= n ; ++i ) {
        cin >> w[i];
    }
    for ( int i = 1 ; i <= n ; ++i ) {
        cin >> b[i];
    }

    for ( int i = 0 ; i < m ; ++i ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    for ( int i = 1 ; i <= n ; ++i ) {
        if ( pass[i] ) continue;
        data.clear();
        dfs(i);
        int sum = 0;
        long long cost = 0ll;
        for ( int v: data ) {
            sum += w[v];
            cost += b[v];
        }
        for ( int i = W ; i >= 0 ; --i ) {
            for ( int v : data ) {
                if ( i >= w[v] ) {
                    dp[i] = max( dp[i], b[v] + dp[i-w[v]] );
                }  
            }
            if ( i >= sum ) {
                dp[i] = max( dp[i], cost + dp[i-sum] );
            }
        }
    }

    cout << dp[W] << endl;

    return 0;
}