#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

int ile[1000010];
int p[1000010], k[1000010];

const int baza = 1<<18;//!!!!!!!!!!!!!!!!!!!!!!!!
int drz[2*baza];

void dod( int gdzie, int co ) {
    gdzie+=baza;
    while( gdzie ) {
        drz[gdzie] = max( drz[gdzie], co );
        gdzie/=2;
    }
}

int czytaj( int gdzie ) {
    gdzie += baza;
    int res=0;
    int pocz = baza;
    while( gdzie ) {
        res = max( drz[gdzie], res );
        if( pocz==gdzie ) return res;
        gdzie = (gdzie-1)/2;
        pocz/=2;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    for( int a, b, i=1; i<=n; i++ ) {
        cin >> a >> b;
        ile[a]++;
        ile[b+1]--;
    }
    int li=0;
    for( int i=1; i<=m; i++ ) {
        li+=ile[i];
        ile[i] = li;
    }

    for( int i=1; i<=m; i++ ) {
        p[i] = czytaj( ile[i] )+1;
        dod( ile[i], p[i] );
    }
    for( int i=0; i<2*baza; i++ ) drz[i] = 0;
    for( int i=m; i>=1; i-- ) {
        k[i] = czytaj( ile[i] )+1;
        dod( ile[i], k[i] );
    }
    int res=0;
    for( int i=1; i<=m; i++ ) {
        res = max( res, p[i]+k[i]-1 );
    }
    cout << res;

    return 0;
}