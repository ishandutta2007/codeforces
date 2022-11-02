#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000ll

bool dp[60][60];
int t[60];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, k;
    cin >> n >> k;
    for( int i=1; i<=n; i++ ) {
        cin >> t[i];
    }
    dp[0][0] = 1;

    int res=0;
    for( int i=60; i>=0; i-- ) {
        res ^= (1ll<<i);
        for( int i=1; i<=n; i++ ) {
            for( int j=1; j<=k; j++ ) {
                dp[i][j] = 0;
                for( int suma=0, x=1; x<=i; x++ ) {
                    suma += t[i-x+1];
                    if( (suma & res) == res && dp[i-x][j-1] ) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        if( !dp[n][k] ) res ^= (1ll<<i);
    }

    cout << res;

    return 0;
}
/*

*/