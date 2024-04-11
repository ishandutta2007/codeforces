#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mod 1000000007

int dp[10000], tab[30], liczba[10000];

int init() {
    int n;
    string s;
    cin >> n >> s;
    for( int i=0; i<26; i++ ) {
        cin >> tab[i];
    }
    dp[0] = 1;
    s = 'a'+s;
    int mi, wyma=0;
    for( int i=1; i<=n; i++ ) {
        liczba[i] = 10000;
    }
    for( int i=1; i<=n; i++ ) {
        mi = tab[s[i]-'a'];
        for( int j=1; j<=mi&&i-j>=0; j++ ) {
            liczba[i] = min( liczba[i], liczba[i-j]+1 );
            wyma = max( wyma, j );
            mi = min( mi, tab[s[i-j]-'a'] );
            dp[i] = (dp[i]+dp[i-j])%mod;
        }
    }
    cout << dp[n] << "\n" << wyma << "\n" << liczba[n];
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    init();
    return 0;
}