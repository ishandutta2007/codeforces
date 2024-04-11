#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int y, b, r;
    cin >> y >> b >> r;
    int res=0;
    for( int i=0; i<1000; i++ ) {
        if( i<=y && i+1<=b && i+2<=r ) res = max( res, 3*i+3 );
    }
    cout << res;

    return 0;
}/*

*/