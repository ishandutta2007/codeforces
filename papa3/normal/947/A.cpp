#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll

int sito[1000010];

void init() {
    sito[1] = 1;
    for( int i=2; i<=1000000; i++ ) {
        if( sito[i] == 0 ) {
            for( int j=i; j<=1000000; j+=i ) {
                sito[j] = i;
            }
        }
    }
}

int n;

int foo( int x ) {
    int p = sito[x];
    if( x-p+1 < 3 ) return n;
    return x-p+1;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    init();
    cin >> n;

    int x = sito[n];
    int res=n;
    for( int i=n-x+1; i<=n; i++ ) {
        res = min( res, foo(i) );
    }
    cout << res;


    return 0;
}