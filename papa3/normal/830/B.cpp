#include<bits/stdc++.h>

using namespace std;

#define int long long

const int baza = 1<<17;

int drz[baza*2];
int ile[baza*2];

void zmien( int gdzie, int ile ) {
    gdzie += baza;
    drz[gdzie] = ile;
    while( gdzie/=2 ) {
        drz[gdzie] = min( drz[gdzie*2], drz[gdzie*2+1] );
    }
}

int czytaj( int pyt_pocz, int pocz=0, int kon=baza, int gdzie=1 ) {
    if( pyt_pocz >= kon ) { return -1; }
    if( gdzie >= baza ) { return gdzie-baza; }
    if( drz[gdzie*2+1] < drz[gdzie*2] ) return czytaj( pyt_pocz, (pocz+kon)/2, kon, gdzie*2+1 );
    int x = czytaj( pyt_pocz, pocz, (pocz+kon)/2, gdzie*2 );
    if( x==-1 && drz[gdzie*2] == drz[gdzie*2+1] ) return czytaj( pyt_pocz, (pocz+kon)/2, kon, gdzie*2+1 );
    return x;
}

int cz( int pyt_pocz, int pyt_kon, int pocz=0, int kon=baza, int gdzie=1 ) {
    if( pyt_kon <= pocz || kon <= pyt_pocz ) { return 0; }
    if( pyt_pocz <= pocz && kon <= pyt_kon ) { return ile[gdzie]; }
    return  cz( pyt_pocz, pyt_kon, pocz, (pocz+kon)/2, gdzie*2 )+
            cz( pyt_pocz, pyt_kon, (pocz+kon)/2, kon, gdzie*2+1 );
}

void zm( int gdzie, int e ) {
    gdzie += baza;
    ile[gdzie] = e;
    while( gdzie/=2 ) {
        ile[gdzie] = ile[gdzie*2]+ile[gdzie*2+1];
    }
}


int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    for( int i=0; i<2*baza; i++ ) {
        drz[i] = 1000000000;
    }
    int n;
    cin >> n;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        zmien( i, a );
        zm( i, 1 );
    }
    int gdzie = 1;
    int wy=0;
    int x;
    for( int i=1; i<=n; i++ ) {
        x = czytaj( gdzie );
        if( x==-1 ) {
            x = czytaj( 1 );
            wy += cz( gdzie, n+1 );
            gdzie = 1;
        }
        wy += cz( gdzie, x+1 );
        gdzie = x;
        zm( gdzie, 0 );
        zmien( gdzie,  1000000000 );
        //cout << wy << '\n';
    }
    cout << wy;

    return 0;
}