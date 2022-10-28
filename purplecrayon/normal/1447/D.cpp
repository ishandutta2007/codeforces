#include "bits/stdc++.h"
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
typedef unsigned int ui;
const int MAXN = 5e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m, dp[MAXN][MAXN];
string a, b;

int dfs(int i, int j){
    if (i >= n || j >= m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j]=0;
    dp[i][j] = max({dp[i][j], dfs(i+1, j)-1, dfs(i, j+1)-1});
    if (a[i] == b[j]) dp[i][j] = max(dp[i][j], 2+dfs(i+1, j+1));
    return dp[i][j];
}
void solve(){
    cin >> n >> m >> a >> b;
    memset(dp, -1, sizeof(dp));
    int ans=0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans = max(ans, dfs(i, j));//, cout << i << ' ' << j << ' ' << dfs(i, j) << '\n';
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}