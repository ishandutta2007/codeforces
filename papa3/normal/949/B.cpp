#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

int tab[200010];
int n;
int foo( int gdzie ) {
    if( gdzie%2 ) return (gdzie+1)/2;

    int nie = gdzie/2;
    return foo( gdzie+n-nie );
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int q;
    cin >> n >> q;

    for( int a, i=0; i<q; i++ ) {
        cin >> a;
        if( a%2 ) cout << (a+1)/2 << "\n";
        else cout << foo( n+a/2 ) << "\n";
    }

    return 0;
}