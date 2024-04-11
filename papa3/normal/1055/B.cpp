#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int tab[1000000];

int ojciec[1000010];

int n, m, l;

int f( int gdzie ) {
    if( gdzie == ojciec[gdzie] ) return gdzie;
    return ojciec[gdzie] = f( ojciec[gdzie] );
}

void u( int a, int b ) {
    ojciec[ f(a) ] = f(b);
}

int res;

void foo( int gdzie, int a ) {
    if( tab[gdzie] > l ) return;
    tab[gdzie] += a;
    if( tab[gdzie] > l ) {
        res++;
        if( tab[gdzie-1] > l ) res--;
        if( tab[gdzie+1] > l ) res--;
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    multiset<int> s;
    cin >> n >> m >> l;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        foo( i, a );
    }
    for( int a, b, c, i=1; i<=m; i++ ) {
        cin >> a;
        if( a == 0 ) cout << res << "\n";
        else {
            cin >> b >> c;
            foo( b, c );
        }
    }

    return 0;
}/*

*/