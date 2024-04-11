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
const int MAXN = 5e3+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

int n, m, k;
ll a[MAXN], ps[MAXN], dp[MAXN][MAXN];
void solve(){
    cin >> n >> m >> k; memset(ps, 0, sizeof(ps));
    for (int i = 0; i < n; i++) cin >> a[i], ps[i+1] = a[i]+ps[i];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = (j?-INF:0);
    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j <= k; j++){
            if (i+m-1 < n && j) dp[i][j]=max(dp[i][j], dp[i+m][j-1]+ps[i+m]-ps[i]);
            dp[i][j] = max(dp[i][j], dp[i+1][j]);
        }
    }
    cout << dp[0][k];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}