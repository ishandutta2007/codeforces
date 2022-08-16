#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 2e5 + 5;

int n, a[N];
vector<int> g[N];

pair<ll, ll> ans[N];
ll dp[N], best = -inf;

void dfs(int x, int p) {
    dp[x] = a[x];
    for (int i : g[x]) {
        if (i == p) continue;
        dfs(i, x);
        dp[x] += dp[i];
    }
}

void dfs1(int x, int p) {
    pair<ll, ll> now = {-inf, -inf};
    for (int i : g[x]) {
        if (i == p) continue;
        dfs1(i, x);
        if (now.first == -inf)
            now.first = ans[i].first;
        else if (now.second == -inf) {
            now.second = ans[i].first;
            if (now.first < now.second)
                swap(now.first, now.second);
        }
        else {
            if (ans[i].first > now.first) {
                now.second = now.first;
                now.first = ans[i].first;
            }
            else if (ans[i].first > now.second)
                now.second = ans[i].first;
        }
    }
    if (now.first != -inf and now.second != -inf)
        best = max(best, now.first + now.second);

    if (dp[x] > now.first) {
        now.second = now.first;
        now.first = dp[x];
    }
    else if (dp[x] > now.second)
        now.second = dp[x];
    ans[x] = now;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (g[1].size() == 1) {
        int c = 0, c1 = 0;
        for (int i = 2; i <= n; i++) {
            c += (g[i].size() == 2);
            c1 += (g[i].size() == 1);
        }
        if (c == n - 2 and c1 == 1) {
            cout << "Impossible\n";
            return 0;
        }
    }

    dfs(1, 1);
    dfs1(1, 1);

    cout << best << "\n";
    return 0;
}