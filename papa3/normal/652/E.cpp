#include<bits/stdc++.h>

using namespace std;

#define int long long
//#define double long double
//#define mod 1000000007ll

int n, m;
vector<pair<int, int> > drogi[300010];
vector<pair<int, int> > edges[300010];
int low[300010];

int li;
int nr[300010];
int czy[300010];
int glebokosc[300010];

void dfs( int gdzie, int skad=0, int gl=1 ) {
    low[gdzie] = gl;
    glebokosc[gdzie] = gl;
    for( pair<int, int> i : drogi[gdzie] ) {
        if( low[i.first] == 0 ) {
            dfs( i.first, gdzie, gl+1 );
        }
    }
    for( pair<int, int> i : drogi[gdzie] ) {
        if( i.first!=skad ) {
            low[gdzie] = min( low[gdzie], low[i.first] );
        }
    }
}

bool odw[300010];

void dfs3( int gdzie, int l=li ) {
    odw[gdzie] = 1;
    for( pair<int, int> i : drogi[gdzie] ) {
        if( odw[i.first] == 0 ) {
            if( low[i.first] > glebokosc[gdzie] )
                dfs3( i.first, ++li );
            else
                dfs3( i.first, l );
        }
    }
    nr[gdzie] = l;
}

void make() {
    for( int i=1; i<=n; i++ ) {
        for( pair<int, int> j : drogi[i] ) {
            if( nr[i] == nr[j.first] ) {
                if( j.second ) czy[ nr[i] ] = 1;
            } else {
                edges[ nr[i] ].push_back( {nr[j.first], j.second} );
                //cout << " " << nr[i] << " " << nr[j.first] << " " << j.second << endl;
            }
        }
    }
}

int przodkowie[300010][20];
bool      skok[300010][20];
pair<int, int> zakres[300010];
int li2;

void dfs2( int gdzie, int skad=0, bool jest=0 ) {
    przodkowie[gdzie][0] = skad;
    skok[gdzie][0] = jest | czy[gdzie] | czy[skad];
    for( int i=1; i<20; i++ ) {
        przodkowie[gdzie][i] = przodkowie[ przodkowie[gdzie][i-1] ][ i-1 ];
        skok[gdzie][i] = skok[gdzie][i-1] | skok[ przodkowie[gdzie][i-1] ][ i-1 ];
    }
    zakres[gdzie].first = ++li2;
    for( pair<int, int> i : edges[gdzie] ) {
        if( i.first != skad ) {
            dfs2( i.first, gdzie, i.second );
        }
    }
    zakres[gdzie].second = ++li2;
}

inline bool czy_przodek( int niby_syn, int niby_ojciec ) {
    return zakres[niby_ojciec].first <= zakres[niby_syn].first && zakres[niby_syn].second <= zakres[niby_ojciec].second;
}

pair<int, bool> lca( int u, int v ) {
    bool wy = czy[u] | czy[v];
    //cout << u << " " << v << "\n";
    if( u==v ) return {u, wy};
    if( czy_przodek( v, u ) ) swap( v, u );
    //cout << u << " " << v << "\n";
    for( int i=19; i>=0; i-- ) {
        if( !czy_przodek( v, przodkowie[u][i] ) ) {
            wy |= skok[u][i];
            u = przodkowie[u][i];
        }
    }
    return {przodkowie[u][0], wy|skok[u][0]};
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n >> m;

    for( int a, b, c, i=1; i<=m; i++ ) {
        cin >> a >> b >> c;
        drogi[a].push_back( {b, c} );
        drogi[b].push_back( {a, c} );
    }

    dfs( 1 );
    dfs3( 1 );
    make();
    dfs2( 0 );

    int a, b;
    cin >> a >> b;

    pair<int, bool> x = lca( nr[a], nr[b] );
    //cout << x.first << "\n";
    bool wy = x.second;
    if( wy | lca( nr[a], x.first ).second | lca( nr[b], x.first ).second ) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
/*

6 7
1 2
1 3
2 3
3 4
4 5
4 6
5 6

*/