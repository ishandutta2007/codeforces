#include <iostream>
#include <tr1/unordered_map>
#include <vector>

using namespace std;
using namespace tr1;

const int N = 1e6 + 10;
const int LIM = 'v' - 'a' + 1;

typedef pair<int, char> pic;

vector< pic > adj[ N ];
unordered_map< int, int > *data[ N ];
int ans[ N ];
int n;

void dfs( int u, int hash, int d ) {
    for ( pic e : adj[u] ) {
        int v = e.first, ch = e.second - 'a';
        dfs( v, hash ^ ( 1 << ch ), d+1 );
    }

    data[u] = new unordered_map<int,int>();
    ans[u] = 0;
    
    for ( pic e : adj[u] ) {
        
        int v = e.first, ch = e.second - 'a';
        
        ans[u] = max( ans[u], ans[v] );

        if ( data[v]->size() > data[u]->size() ) {
            swap( data[u], data[v] );
        }

        for ( auto x : *data[v] ) {
            for ( int i = 0 ; i <= LIM ; ++i ) {
                int val = x.first ^ ( i == LIM ? 0 : ( 1 << i ) );
                auto it =  data[u]->find(val);
                if ( it != data[u]->end() ) {
                    ans[u] = max( ans[u], x.second + it->second - 2 * d );
                }
            }
        }
        for ( auto x : *data[v] ) {
            (*data[u])[ x.first ] = max( (*data[u])[ x.first ], x.second );
        }
        data[v]->clear();
    }

    for ( int i = 0 ; i <= LIM ; ++i ) {
        int val = hash ^ ( i == LIM ? 0 : ( 1 << i ) );
        if ( data[u]->find(val) != data[u]->end() ) {
            ans[u] = max( ans[u], (*data[u])[val] - d );
        }
    }
    (*data[u])[ hash ] = max( (*data[u])[ hash ], d );

}
int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    cin >> n;
    for ( int i = 2 ; i <= n ; ++i ) {
        int v;
        char ch;
        cin >> v >> ch;
        adj[v].push_back( pic(i, ch) );
    }

    dfs(1, 0, 0);

    for ( int i = 1 ; i <= n ; ++i ) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}