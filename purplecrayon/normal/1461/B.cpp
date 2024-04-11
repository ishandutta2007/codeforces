#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXM = 1e2+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};


void solve(){
    int n, m; cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        char c; cin >> c;
        g[i][j] = c=='*';
    }
    vector<vector<int>> dp(n, vector<int>(m));
    ll ans=0;
    for (int i = n-1; i >= 0; i--) for (int j = 0; j < m; j++) if (g[i][j]) {
        dp[i][j] = 1;
        if (j > 0 && j < m-1 && i < n-1 && g[i+1][j-1] && g[i+1][j+1] && g[i+1][j]) dp[i][j] = min(dp[i+1][j-1], dp[i+1][j+1])+1;
        ans += dp[i][j];
    }
    cout << ans << '\n';

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}