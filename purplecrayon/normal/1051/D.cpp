#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e3+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 2e3+10, INF = 1e9+10;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, K, c[4][4]={{0, 1, 1, 1},{0, 0, 2, 0},{0, 2, 0, 0},{1, 1, 1, 0}};
ll dp[MAXN][MAXK][4];

void solve(){
    cin >> n >> K; memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 4; i++) dp[0][i==0||i==3?1:2][i]++;
    for (int i = 1; i < n; i++) for (int j = 1; j <= K; j++) for (int k = 0; k < 4; k++) for (int l = 0; l < 4; l++)
        dp[i][j][k] = (dp[i][j][k]+(c[l][k]>=j?0:dp[i-1][j-c[l][k]][l]))%MOD;
    // for (int i = 0; i < n; i++) for (int j = 1; j <= K; j++) for (int k = 0; k < 4; k++)  cout << i << " " << j << " " << bitset<2>(k) << " " << dp[i][j][k] << '\n';
    ll ans=0;
    for (int i = 0; i < 4; i++) ans = (ans+dp[n-1][K][i])%MOD;
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}