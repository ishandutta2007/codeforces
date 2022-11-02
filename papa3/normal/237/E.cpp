#include<bits/stdc++.h>

using namespace std;

#define INF 10000000

struct przeplyw {
    struct edge {
        int to, flow, rev, cost;
    };
    vector<vector<edge> > drogi;
    vector<int> dist, from;
    int maxN, source, wy;


    void addEdge( int u, int v, int flow, int cost ) {
        int szU = drogi[u].size();
        int szV = drogi[v].size();
        drogi[u].push_back( {v, flow, szV, cost} );
        drogi[v].push_back( {u, 0, szU, -cost} );
    }
    przeplyw( int N ) : drogi( N+10 ), maxN( N ), dist( N+10 ), from( N+10 ) {
        for( int i=1; i<=26; i++ ) {
            addEdge( i, 0, 200, 0 );
        }
        wy = 0;
    }

    void bellman( int litera ) {
        for( int i=0; i<=maxN; i++ ) {
            dist[i] = INF;
        }
        dist[source] = 0;
        queue<int> kol;
        kol.push( source );
        int x;
        while( !kol.empty() ) {
            x = kol.front();
            kol.pop();
            if( x == 0 ) continue;
            for( edge & i : drogi[x] ) {
                if( i.to == 0 && x != litera ) continue;
                if( i.flow == 0 ) continue;
                if( dist[i.to] > dist[x]+i.cost ) {
                    dist[i.to] = dist[x]+i.cost;
                    from[i.to] = i.rev;
                    kol.push( i.to );
                }
            }
        }
    }

    bool algo( int Source, int litera ) {
        source = Source;
        bellman( litera );
        if( dist[0] == INF ) return false;
        wy += dist[0];
        int gdzie = 0;
        while( gdzie != source ) {
            edge* x = &drogi[gdzie][ from[gdzie] ];
            x->flow++;
            drogi[x->to][x->rev].flow--;
            gdzie = x->to;
        }
        return true;
    }
};

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    string t;
    int n;
    cin >> t >> n;
    przeplyw p( 2*n+100 );
    int tab[30];
    for( int i=27; i<n+27; i++ ) {
        string s;
        int a;
        cin >> s >> a;
        p.addEdge( i, i+n, a, i-26 );
        for( int j=1; j<=26; j++ ) {
            tab[j] = 0;
        }
        for( char c : s ) {
            tab[c-'a'+1]++;
        }
        for( int j=1; j<=26; j++ ) {
            p.addEdge( i+n, j, tab[j], 0 );
        }
        p.addEdge( 2*n+90, i, INF, 0 );//source
    }
    for( char c : t ) {
        if( !p.algo( 2*n+90, c-'a'+1 ) ) {
            cout << -1;
            return 0;
        }
    }
    cout << p.wy;

    return 0;
}