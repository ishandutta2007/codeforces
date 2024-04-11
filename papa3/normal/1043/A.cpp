#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    int s=0;
    int ma=0;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        s += a;
        ma = max( ma, a );
    }

    for( int i=ma; ; i++ ) {
        if( i*n-s > s ) {
            cout << i;
            return 0;
        }
    }

    return 0;
}/*

*/