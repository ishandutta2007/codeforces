#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 4e3+10, MOD = 1e9+7;
const ll INF = 1e18+10;

int n, m, a[N], par[N];
vector<int> adj[N];
ll dp[N][N];

int dfs(int c) {
    int cur_sub = 1;
    vector<ll> pdp(cur_sub + 1);
    for (int nxt : adj[c]) {
        ll w = abs(a[nxt] - a[c]);
        int nxt_sub = dfs(nxt);
        vector<ll> ndp(cur_sub + nxt_sub + 1, -INF);
        for (int a = 0; a <= cur_sub; a++) {
            for (int b = 0; b <= nxt_sub; b++) {
                ndp[a + b] = max(ndp[a + b], pdp[a] + dp[nxt][b] + w * (m - b) * b);
            }
        }
        cur_sub += nxt_sub;
        pdp = ndp;
    }
    for (int i = 0; i < sz(pdp); i++) dp[c][i] = pdp[i];
    return cur_sub;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> st;
    memset(par, -1, sizeof(par));
    for (int i = 0; i < n; i++) {
        int last = -1;
        while (sz(st) && a[st.back()] >= a[i]) {
            last = st.back();
            st.pop_back();
        }
        if (sz(st))
            par[i] = st.back();
        if (last != -1)
            par[last] = i;

        st.push_back(i);
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (par[i] == -1) root = i;
        else adj[par[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) for (int j = 0; j <= m; j++)
        dp[i][j] = -INF;

    dfs(root);
    cout << dp[root][m] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}