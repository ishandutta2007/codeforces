#include<bits/stdc++.h>

using namespace std;

int odl[1000010];
vector<int> edges[1000010];
bool czy[1000010];

void dfs( int where=1, int from=0, int dist=0 ) {
    odl[where] = dist;
    dist++;
    for( int i : edges[where] ) {
        if( i == from ) continue;
        dfs( i, where, dist );
    }
}

void dfs2( int where, int from=0, int dist=0 ) {
    dist++;
    czy[where] = true;
    for( int i : edges[where] ) {
        if( i == from ) continue;
        if( dist < odl[i] ) {
            dfs2( i, where, dist );
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, x;
    cin >> n >> x;
    for( int a, b, i=1; i<n; i++ ) {
        cin >> a >> b;
        edges[a].push_back( b );
        edges[b].push_back( a );
    }
    dfs();
    dfs2( x );
    int wy=0;
    for( int i=1; i<=n; i++ ) {
        if( czy[i] ) {
            wy = max( wy, odl[i] );
        }
    }
    cout << wy*2;

    return 0;
}/*
1
3
1
1 5
*/