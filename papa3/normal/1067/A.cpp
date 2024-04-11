#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 998244353ll
#define INF 1000000000000000000ll

int dp[100010][210];
int zl[100010][210];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    int a;
    cin >> a;
    if( a==-1 ) {
        for( int i=1; i<=200; i++ ) zl[1][i] = 1;
    } else {
        zl[1][a] = 1;
    }
    for( int i=2; i<=n; i++ ) {
        cin >> a;
        for( int suma=0, j=200; j>=1; j-- ) {
            suma += dp[i-1][j];
            suma %= mod;
            dp[i][j] = suma;
        }
        for( int suma=0, j=1; j<=200; j++ ) {
            dp[i][j] += zl[i-1][j];
            dp[i][j] %= mod;
        }
        for( int suma=0, j=1; j<=200; j++ ) {
            suma += zl[i-1][j-1]+dp[i-1][j-1];
            suma %= mod;
            zl[i][j] = suma;
        }
        if( a!=-1 ) {
            for( int j=1; j<=200; j++ ) {
                if( a==j ) continue;
                dp[i][j] = zl[i][j] = 0;
            }
        }
    }
    int res=0;
    for( int i=1; i<=200; i++ ) {
        res += dp[n][i];
    }
    cout << res%mod;

    return 0;
}/*

*/