#include<bits/stdc++.h>

using namespace std;

#define int long long

int dp[2][1000010], t[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );


    int n;
    cin >> n;
    int wy=0;
    for( int i=2; i<=n+1; i++ ) {
        cin >> t[i];
        if( i==2 ) continue;
        dp[1][i] = max( 0ll, dp[0][i-1] )+abs( t[i-1]-t[i] );
        wy = max( wy, dp[1][i] );
        dp[0][i] = max( 0ll, dp[1][i-1]-abs( t[i-1]-t[i] ) );
        wy = max( wy, dp[0][i] );
    }
    cout << wy;

    return 0;
}