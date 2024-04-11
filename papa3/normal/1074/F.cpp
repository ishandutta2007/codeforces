#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

vector<int>     drogi[1000010];
pair<int, int> zakres[1000010];
int przodkowie[1000010][20];

int li=0;
void dfs( int gdzie=1, int skad=0 ) {
    zakres[gdzie].first = ++li;
    for( int i=1; i<20; i++ ) {
        przodkowie[gdzie][i] = przodkowie[ przodkowie[gdzie][i-1] ][i-1];
    }
    for( int i : drogi[gdzie] ) {
        if( i == skad ) continue;
        przodkowie[i][0] = gdzie;
        dfs( i, gdzie );
    }
    zakres[gdzie].second = li+1;
}

const int baza = 1<<20;
pair<int, int> drz[2*baza];
int to_push[2*baza];

void akt( int gdzie, int co ) {
    to_push[gdzie] += co;
    drz[gdzie].first += co;
}

void zwal( int gdzie ) {
    akt( gdzie*2, to_push[gdzie] );
    akt( gdzie*2+1, to_push[gdzie] );
    to_push[gdzie]=0;
}

void napraw( int gdzie ) {
    drz[gdzie].first = min( drz[gdzie*2].first, drz[gdzie*2+1].first );
    drz[gdzie].second = 0;
    if( drz[gdzie].first == drz[gdzie*2].first )   drz[gdzie].second += drz[gdzie*2].second;
    if( drz[gdzie].first == drz[gdzie*2+1].first ) drz[gdzie].second += drz[gdzie*2+1].second;
}

void add( int co, int pyt_pocz, int pyt_kon, int pocz=0, int kon=baza, int gdzie=1 ) {
    if( pyt_pocz <= pocz && kon <= pyt_kon ) {
        akt( gdzie, co );
        return;
    }
    if( kon <= pyt_pocz || pyt_kon <= pocz ) {
        return;
    }
    zwal( gdzie );
    int sr = (pocz+kon)/2;
    add( co, pyt_pocz, pyt_kon, pocz, sr, gdzie*2 );
    add( co, pyt_pocz, pyt_kon, sr, kon, gdzie*2+1 );
    napraw( gdzie );
}

bool czy_przodek( int niby_syn, int niby_ojciec ) {
    return zakres[niby_ojciec].first <= zakres[niby_syn].first && zakres[niby_syn].second <= zakres[niby_ojciec].second;
}

void algo( int a, int b, int x ) {
    add( -x, zakres[a].first, zakres[a].second );
    for( int i=19; i>=0; i-- ) {
        if( !czy_przodek( b, przodkowie[a][i] ) ) {
            a = przodkowie[a][i];
        }
    }
    add( x, zakres[a].first, zakres[a].second );
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, q;
    cin >> n >> q;
    for( int a, b, i=1; i<n; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
    }
    for( int i=baza; i<2*baza; i++ ) drz[i] = {1, 1};
    for( int i=baza-1; i>0; i-- ) {
        napraw( i );
    }

    przodkowie[1][0] = 1;
    dfs();

    add( -1, zakres[1].first, zakres[1].second );
    map<pair<int, int>, int> m;
    for( int a, b, i=1; i<=q; i++ ) {
        cin >> a >> b;
        if( a>b ) swap( a, b );
        pair<int, int> p = {a, b};
        int x = ++m[p];
        x%=2;
        if( x==0 ) x = -1;
        if( czy_przodek( a, b ) ) {
            algo( a, b, x );
        } else if( czy_przodek( b, a ) ) {
            algo( b, a, x );
        } else {
            add( x, zakres[1].first, zakres[1].second );
            add( -x, zakres[a].first, zakres[a].second );
            add( -x, zakres[b].first, zakres[b].second );
        }
        if( drz[1].first == 0 ) {
            cout << drz[1].second << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}/*

*/