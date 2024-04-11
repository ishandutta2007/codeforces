#include<bits/stdc++.h>

using namespace std;

//#define iny long long

deque<pair<int, int> > d[1000];

int tab[510][510];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=m; j++ ) {
            tab[i][j] = numeric_limits<int>::max();
        }
    }
    for( int a, b, c, i=1; i<=q; i++ ) {
        cin >> a >> b >> c;
        tab[a][b] = c;
    }

    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<k; j++ ) {
            while( !d[i].empty() && d[i].back().second < tab[i][j] ) {
                d[i].pop_back();
            }
            d[i].push_back( {j, tab[i][j]} );
        }
    }
    int wy = numeric_limits<int>::max();
    for( int j=k; j<=m; j++ ) {
        for( int i=1; i<=n; i++ ) {
            if( d[i].front().first == j-k ) {
                d[i].pop_front();
            }
            while( !d[i].empty() && d[i].back().second < tab[i][j] ) {
                d[i].pop_back();
            }
            d[i].push_back( {j, tab[i][j]} );
        }
        deque<pair<int, int> > kol;
        for( int i=1; i<k; i++ ) {
            while( !kol.empty() && kol.back().second < d[i].front().second ) {
                kol.pop_back();
            }
            kol.push_back( {i, d[i].front().second} );
        }
        for( int i=k; i<=n; i++ ) {
            if( kol.front().first == i-k ) {
                kol.pop_front();
            }
            while( !kol.empty() && kol.back().second < d[i].front().second ) {
                kol.pop_back();
            }
            kol.push_back( {i, d[i].front().second} );
            wy = min( wy, kol.front().second );
        }
    }
    if( wy == numeric_limits<int>::max() ) cout << -1;
    else cout << wy;

    return 0;
}