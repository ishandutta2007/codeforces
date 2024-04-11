#include<bits/stdc++.h>

using namespace std;

const int baza = 1 << 16;
int drz[baza*2], to_push[baza*2];

void akt( int gdzie, int ile ) {
    to_push[gdzie] += ile;
    drz[gdzie] += ile;
}

void zwal( int gdzie ) {
    akt( gdzie*2, to_push[gdzie] );
    akt( gdzie*2+1, to_push[gdzie] );
    to_push[gdzie] = 0;
}

int czytaj( int pyt_pocz, int pyt_kon, int pocz=0, int kon=baza, int gdzie=1 ) {
    if( pyt_kon <= pocz || kon <= pyt_pocz ) return 0;
    if( pyt_pocz <= pocz && kon <= pyt_kon ) return drz[gdzie];
    zwal( gdzie );
    int sr = (pocz+kon)/2;
    return max( czytaj( pyt_pocz, pyt_kon, pocz, sr, gdzie*2 ), czytaj( pyt_pocz, pyt_kon, sr, kon, gdzie*2+1 ) );
}

void dodaj( int pyt_pocz, int pyt_kon, int ile, int pocz=0, int kon=baza, int gdzie=1 ) {
    if( pyt_kon <= pocz || kon <= pyt_pocz ) return;
    if( pyt_pocz <= pocz && kon <= pyt_kon ) {
        akt( gdzie, ile );
        return;
    }
    zwal( gdzie );
    int sr = (pocz+kon)/2;
    dodaj( pyt_pocz, pyt_kon, ile, pocz, sr, gdzie*2 );
    dodaj( pyt_pocz, pyt_kon, ile, sr, kon, gdzie*2+1 );
    drz[gdzie] = max( drz[gdzie*2], drz[gdzie*2+1] );
}

void zeruj() {
    for( int i=1; i<2*baza; i++ ) {
        drz[i] = to_push[i] = 0;
    }
}

void make() {
    for( int i=baza-1; i>0; i-- ) {
        drz[i] = max( drz[i*2], drz[i*2+1] );
    }
}

int dp[35010];
int tab[35010];
int ost[35010];
int pom[35010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, k;
    cin >> n >> k;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
        ost[i] = pom[ tab[i] ];
        pom[ tab[i] ] = i;
    }
    while( k-- ) {
        for( int i=1; i<=n; i++ ) {
            dodaj( ost[i], i, 1 );
            dp[i] = czytaj( 0, i );
        }
        zeruj();
        for( int i=1; i<=n; i++ ) {
            drz[i+baza] = dp[i];
        }
    }
    cout << dp[n];

    return 0;
}