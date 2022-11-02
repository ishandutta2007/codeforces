#include<bits/stdc++.h>

using namespace std;

#define int long long

int tab[100];
int pref[100];
int dp[100];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=n; i>=1; i-- ) {
        cin >> tab[i];
    }
    for( int i=1; i<=n; i++ ) {
        pref[i] = tab[i]+pref[i-1];
        dp[i] = max( tab[i]+pref[i-1]-dp[i-1], dp[i-1] );
    }
    cout << pref[n]-dp[n] << " " << dp[n];

    return 0;
}