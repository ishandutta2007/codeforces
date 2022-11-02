#include<bits/stdc++.h>

using namespace std;

//#define int long long

bool visited[200010];
vector<pair<int, int> > drogi[200010];
int pocz[200010];

struct moj{
    int a, b, c;
};
vector<moj> odp;

bool dfs( int where, int from=0 ) {
    int x=0, y=0;
    int i;
    for( ; pocz[where]<drogi[where].size(); pocz[where]++ ) {
        i = pocz[where];
        if( visited[ drogi[where][i].second ] ) continue;
        visited[ drogi[where][i].second ] = true;
        bool czy = dfs( drogi[where][i].first, where );
        if( czy ) {
            x = drogi[where][i].first;
            if( y != 0 ) {
                odp.push_back( {x, where, y} );
                x = y = 0;
            } else {
                y = x;
            }
        }
    }
    if( x && from ) {
        odp.push_back( {x, where, from} );
        return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    for( int a, b, i=1; i<=m; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( {b, i} );
        drogi[b].push_back( {a, i} );
    }
    for( int i=1; i<=n; i++ ) {
        dfs( i );
    }
    cout << odp.size() << "\n";
    for( auto & i : odp ) {
        cout << i.a << ' ' << i.b << " " << i.c << "\n";
    }


    return 0;
}