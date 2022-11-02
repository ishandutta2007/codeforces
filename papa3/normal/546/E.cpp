#include<bits/stdc++.h>

using namespace std;

int ile[500], szuk[500], odp[300][300];

struct przeplyw {
    struct edge {
        int to, flow, rev;
    };
    void addEdge( int u, int v, int flow ) {
        int szU = drogi[u].size(),
            szV = drogi[v].size();
        drogi[u].push_back( {v, flow, szV} );
        drogi[v].push_back( {u, 0, szU} );
    }
    vector<vector<edge> > drogi;
    vector<bool> odw;
    int maxN;
    int source;

    przeplyw( int N ) : maxN(N), drogi(N+10), odw(N+10) {}

    int dfs( int gdzie, int maxFlow ) {
        if( ile[gdzie] < szuk[gdzie] ) {
            ile[gdzie] += maxFlow;
            return maxFlow;
        }
        odw[gdzie] = true;
        for( edge & i : drogi[gdzie] ) {
            if( odw[i.to] ) { continue; }
            if( i.flow == 0 ) { continue; };
            int x = dfs( i.to, min( maxFlow, i.flow ) );
            if( x ) {
                i.flow -= x;
                drogi[i.to][i.rev].flow += x;
                return x;
            }
        }
        return 0;
    }

    int algo( int Source, int toFlow ) {
        source = Source;
        int x, wy=0;
        do {
            for( int i=0; i<=maxN; i++ ) {
                odw[i] = false;
            }
            x = dfs( source, toFlow );
            wy += x;
            toFlow -= x;
        } while( x && toFlow );
        return wy;
    }

    void zrob( int n ) {
        for( int i=1; i<=n; i++ ) {
            for( edge & j : drogi[i+n] ) {
                odp[i][j.to] = numeric_limits<int>::max()-j.flow;
            }
            odp[i][i] = drogi[i][0].flow;
        }
    }
};



int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, m;
    cin >> n >> m;
    przeplyw p( n*2 );
    for( int i=1; i<=n; i++ ) {
        cin >> ile[i];
        p.addEdge( i, i+n, ile[i] );
    }
    for( int i=1; i<=n; i++ ) {
        cin >> szuk[i];
    }
    for( int a, b, i=1; i<=m; i++ ) {
        cin >> a >> b;
        p.addEdge( a+n, b, numeric_limits<int>::max() );
        p.addEdge( b+n, a, numeric_limits<int>::max() );
    }

    bool czy=true;
    int li=n+5;
    while( czy && li ) {
        czy = false;
        li--;
        for( int i=1; i<=n; i++ ) {
            if( ile[i] > szuk[i] ) {
                if( p.algo( i, ile[i]-szuk[i] ) == ile[i]-szuk[i] ) {
                    czy = true;
                    ile[i] = szuk[i];
                    break;
                } else {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    for( int i=1; i<=n; i++ ) {
        if( ile[i] != szuk[i] ) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    p.zrob( n );
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=n; j++ ) {
            cout << odp[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}

/*struct przeplyw {
    bool droga[300][300];
    int tab[300][300];
    int ile[300];
    bool odw[300], per[300];
    int maxN;
    int Source;
    przeplyw( int N ) : maxN(N) {}

    int dfs( int gdzie, int maxFlow ) {
        if( per[gdzie] == false ) {
            ile[gdzie] += maxFlow
        }
    }

    int algo( int Source ) {
        source = Source;
        int x, wy=0;
        do {
            for( int i=1; i<=maxN; i++ ) {
                odw[i] = false;
            }
            x = dfs( source, numeric_limits<int>::max() );
            wy += x;
        } while( x );
        return wy;
    }
};

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
}*/