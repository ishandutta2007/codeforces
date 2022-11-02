#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define LOG 19

map<int, int> m;
vector<pair<int, int> > drogi[1000010];

int rozmiar[1000010];

int przodkowie[1000010][LOG+2];
int       ksor[1000010][LOG+2];
int     glebia[1000010];

void dfs( int gdzie ) {
    for( int i=1; i<LOG; i++ ) {
        przodkowie[gdzie][i] = przodkowie[ przodkowie[gdzie][i-1] ][ i-1 ];
        ksor[gdzie][i] = ksor[gdzie][i-1]^ksor[ przodkowie[gdzie][i-1] ][i-1];
    }
    for( pair<int, int> i : drogi[gdzie] ) {
        if( i.first == przodkowie[gdzie][0] ) continue;
        przodkowie[i.first][0] = gdzie;
        ksor[i.first][0] = i.second;
        glebia[i.first] = glebia[gdzie]+1;
        dfs( i.first );
    }
}

void u( int a, int b, int c ) {
    int aa = przodkowie[a][LOG-1];
    int bb = przodkowie[b][LOG-1];
    if( aa==bb ) return;
    if( rozmiar[aa] > rozmiar[bb] ) {
        swap( aa, bb );
        swap( a, b );
    }
    rozmiar[bb] += rozmiar[aa];
    drogi[a].push_back( {b, c} );
    drogi[b].push_back( {a, c} );
    przodkowie[a][0] = b;
    ksor[a][0] = c;
    glebia[a] = glebia[b]+1;
    dfs( a );
}

int algo( int a, int b ) {
    if( przodkowie[a][LOG-1] != przodkowie[b][LOG-1] ) return -1;
    if( glebia[b] > glebia[a] ) swap( a, b );
    int res=0;
    for( int i=LOG-1; i>=0; i-- ) {
        if( glebia[ przodkowie[a][i] ] >= glebia[b] ) {
            res ^= ksor[a][i];
            a = przodkowie[a][i];
        }
    }
    if( a==b ) return res;
    for( int i=LOG-1; i>=0; i-- ) {
        if( przodkowie[a][i] != przodkowie[b][i] ) {
            res ^= ksor[a][i];
            res ^= ksor[b][i];
            a = przodkowie[a][i];
            b = przodkowie[b][i];
        }
    }
    return res^ksor[a][0]^ksor[b][0];
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int q;
    cin >> q;
    for( int i=0; i<=3*q; i++ ) {
        rozmiar[i] = 1;
        for( int j=0; j<LOG; j++ ) {
            przodkowie[i][j] = i;
        }
    }
    int last=0;
    int t, l, r, x;
    int li=0;
    while( q-- ) {
        cin >> t >> l >> r;
        l ^= last;
        r ^= last;
        if( l>r ) swap( l, r );
        r++;
        if( m[l] == 0 ) m[l] = ++li;
        if( m[r] == 0 ) m[r] = ++li;
        l = m[l];
        r = m[r];
        //cout << l << " " << r << endl;
        if( t==2 ) {
            last = algo( l, r );
            cout << last << "\n";
            //cout << endl;
            last = abs( last );
        } else {
            cin >> x;
            x ^= last;
            u( l, r, x );
        }
        //cout << endl;
    }

    return 0;
}/*

*/