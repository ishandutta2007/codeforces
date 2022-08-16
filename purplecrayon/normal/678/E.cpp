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
typedef unsigned int ui;
const int MAXN = 18, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 2*MAXA;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n;
ld p[MAXN][MAXN], dp[1<<MAXN][MAXN];
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> p[i][j];
    memset(dp, 0, sizeof(dp)); cout << fixed << setprecision(15);
    dp[1][0] = 1; //prob that he will win if this is curr state
    for (int i = 1; i < (1<<n); i++) for (int j = 0; j < n; j++) if (i&(1<<j)) {
        for (int k = 0; k < n; k++) if (i&(1<<k)) {
            dp[i][j] = max(dp[i][j], p[j][k]*dp[i^(1<<k)][j]+p[k][j]*dp[i^(1<<j)][k]);
        }
    }
    ld ans=0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[(1<<n)-1][i]);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}