#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000

pair<int, int> dp[1000010];
vector<int> drogi[1000010];
int t[1000010];

void dfs( int gdzie=1, int skad=1 ) {
    dp[gdzie] = {1, 0};
    for( int i : drogi[gdzie] ) {
        if( i != skad ) {
            dfs( i, gdzie );
            dp[gdzie].first += dp[i].second;
            dp[gdzie].second += dp[i].first;
        }
    }
}

int res;

void algo( int gdzie=1, int skad=1, pair<int, int> p = {dp[1].second, dp[1].first} ) {
    swap( p.first, p.second );
    p.first -= dp[gdzie].first;
    p.second -= dp[gdzie].second;
    res = (res + p.first*t[gdzie]+mod*mod)%mod;
    p.first++;
    for( int i : drogi[gdzie] ) {
        if( i != skad ) {
            res = (res+ ((p.first*dp[i].second-p.second*dp[i].first+mod*mod)%mod)*t[gdzie]+mod*mod )%mod;
            p.first += dp[i].second;
            p.second += dp[i].first;
        }
    }
    for( int i : drogi[gdzie] ) {
        if( i != skad ) {
            algo( i, gdzie, p );
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> t[i];
    }
    for( int a, b, i=1; i<n; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
    }
    dfs();
    algo();
    res*=2;
    for( int i=1; i<=n; i++ ) {
        res = (res+t[i]+mod)%mod;
    }
    cout << res;

    return 0;
}
/*

*/