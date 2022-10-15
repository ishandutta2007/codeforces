// ./e-move-and-swap.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e5 + 1;
int N,
    P[MN];
ll V[MN];

int dep[MN];
vector<int> g[MN];
ll dp[MN], mn[MN], mx[MN], mndep[MN], mxdep[MN];

void solve() {
    cin >> N;
    for (auto i = 1; i <= N; i++) g[i].clear();
    for (auto i = 2; i <= N; i++) {
        int p; cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    for (auto i = 2; i <= N; i++) cin >> V[i];
    function<void(int, int)> dfs = [&] (int c, int p) {
        for (auto to : g[c]) {
            if (to != p) {
                dep[to] = dep[c] + 1;
                P[to] = c;
                dfs(to, c);
            }
        }
    };
    dfs(1, -1);
    vector<vector<int>> ord(*max_element(dep, dep+N+1)+1);
    for (auto i = 1; i <= N; i++)
        ord[dep[i]].push_back(i);

    // reset stuff
    fill(mx, mx + N + 1, -INF);
    fill(mn, mn + N + 1, INF);
    fill(mxdep, mxdep + N + 1, -INF);
    fill(mndep, mndep + N + 1, INF);
    for (auto i = 1; i <= N; i++) {
        for (auto to : g[i]) {
            if (dep[to] > dep[i]) {
                mx[i] = max(mx[i], V[to]);
                mn[i] = min(mn[i], V[to]);
            }
        }
        mxdep[dep[i]] = max(mxdep[dep[i]], V[i]);
        mndep[dep[i]] = min(mndep[dep[i]], V[i]);
    }

    // solve DP
    fill(dp, dp+N+1, 0);
    ll ans = 0;
    set<ll, greater<ll>> lT, rT;
    for (auto d = 0; d < (int)ord.size(); d++) {
        // answer DP values w/ SWAP
        for (auto i : ord[d]) {
            // swap
            // dp[j] = max(dp[j], dp[i] + max(abs(V[j] - mx[i]), abs(V[j] - mn[i])));
            if (i != 1)
                dp[i] = max({dp[i], *lT.begin() + V[i], *rT.begin() - V[i]});

            ans = max(ans, dp[i]);
        }

        // propagate dp values
        lT.clear(); rT.clear();
        for (auto i : ord[d]) {
            // don't swap
            for (auto to : g[i])
                if (to != P[i])
                    dp[to] = max(dp[to], dp[i] + max(abs(V[to] - mxdep[d+1]), abs(V[to] - mndep[d+1])));

            // swap
            // dp[j] = max(dp[j], dp[i] + max(abs(V[j] - mx[i]), abs(V[j] - mn[i])));
            // V[j]-mx[i], V[j]-mn[i]
            lT.insert(dp[i] - mx[i]);
            lT.insert(dp[i] - mn[i]);
            // mx[i]-V[j], mn[i]-V[j]
            rT.insert(dp[i] + mx[i]);
            rT.insert(dp[i] + mn[i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}