#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000ll

int n, L;

vector<int> v, v2;

int ojciec[1000010];

int f( int gdzie ) {
    if( gdzie == ojciec[gdzie] ) return gdzie;
    return ojciec[gdzie] = f( ojciec[gdzie] );
}

bool foo( int x ) {
    int l=0, r=2*n;
    int l2=0, r2=2*n;
    int pocz=0, kon=0;

    int a=-1;
    int p, q;
    for( int i=0; i<=n; i++ ) ojciec[i] = i;
    for( int i : v ) {
        a++;
        while( abs( i-v2[pocz] ) > x && pocz<v2.size()-1 ) pocz++;
        kon = max( pocz, kon );
        while( abs( i-v2[kon] ) <= x && kon<v2.size()-1 ) kon++;
        if( kon-pocz >= n ) continue;
        if( kon==pocz ) return 0;
        kon--;
        p = (pocz-a+n)%n;
        q = (kon-a+n)%n;
        if( x==17 ) {
            cout << p << " " << q << "\n";
        }
        if( p<=q ) {
            for( int j=f(0); j<p; j=f(j) ) {
                ojciec[ j ] = j+1;
            }
            for( int j=f(q+1); j<n; j=f(j) ) {
                ojciec[ j ] = j+1;
            }
        } else {
            for( int j=f(q+1); j<p; j=f(j) ) {
                ojciec[ j ] = j+1;
            }
        }
    }
    return f(0) < n;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n >> L;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        v.push_back( a+L );
    }
    sort( v.begin(), v.end() );
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        v2.push_back( a );
    }
    sort( v2.begin(), v2.end() );
    for( int i=0; i<n; i++ ) {
        v2.push_back( v2[i]+L );
    }
    for( int i=0; i<n; i++ ) {
        v2.push_back( v2[i]+L+L );
    }

    int pocz=-1, kon=L/2+1, sr;
    while( kon-pocz > 1 ) {
        sr = (kon+pocz)/2;
        if( foo( sr ) ) kon=sr;
        else pocz = sr;
    }
    cout << kon;

    return 0;
}
/*

*/