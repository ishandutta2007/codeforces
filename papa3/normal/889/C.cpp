#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mod 1000000007

int dp[1000010];
int silnia[1000010];

int pot( int n, int k = mod-2 ) {
    int res = 1;
    while( k ) {
        if( k%2 ) {
            res = (res*n)%mod;
        }
        n = (n*n)%mod;
        k/=2;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, k;
    cin >> n >> k;
    if( k>n-2 ) {
        cout << 0;
        return 0;
    }
    dp[1] = 1;
    silnia[0] = 1;
    for( int i=1; i<=n; i++ ) {
        silnia[i] = (silnia[i-1]*i)%mod;
    }
    for( int i=2; i<=n; i++ ) {
        dp[i] = ((i-1)*dp[i-1])%mod;
        if( i>k+1 )
            dp[i] -= ((dp[i-1-k]*silnia[i-2])%mod*pot( silnia[i-2-k] ))%mod;
        while( dp[i] < 0 ) dp[i]+=mod;
    }
    int res = 0;
    for( int i=1; i<=n; i++ ) {
        res = (res+ (dp[i]*silnia[n-1])%mod*pot( silnia[i-1] ) )%mod;
    }
    res = silnia[n]-res;
    //cout << res << "\n" << mod << "\n";
    while( res<0ll ) {
        res += mod;
    }
    cout << res;

    return 0;
}/*
1000000 99998
*/