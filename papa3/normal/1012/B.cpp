#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007LL
#define INF 1000000000000000000LL

int ojciec[1000010];

int f( int gdzie ) {
    if( gdzie == ojciec[gdzie] ) return gdzie;
    return ojciec[gdzie] = f( ojciec[gdzie] );
}

void u( int a, int b ) {
    ojciec[ f(a) ] = f(b);
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m, q;
    cin >> n >> m >> q;
    for( int i=0; i<=n+m+10; i++ ) ojciec[i] = i;
    for( int a, b, i=1; i<=q; i++ ) {
        cin >> a >> b;
        b+=n;
        u( a, b );
    }
    int ile=-1;
    for( int i=1; i<=n+m; i++ ) {
        if( ojciec[i] == i ) ile++;
    }
    cout << ile;

    return 0;
}
/*

*/