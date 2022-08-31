#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, k, d[N], p[N];
vector<int> g[N];

set<int> s;

void dfs(int x) {
    int f = 1;
    for (int &i : g[x]) {
        if (i == p[x]) continue;
        if (d[i] == 0) {
            d[i] = 1 + d[x];
            p[i] = x;
            dfs(i);
        }
        else if (d[i] < d[x] and d[x] - d[i] < k) {
            vector<int> ans;
            while (x != i) {
                ans.push_back(x);
                x = p[x];
            }
            ans.push_back(i);
            cout << 2 << "\n";
            cout << ans.size() << "\n";
            for (int u : ans) cout << u << " ";
            exit(0);
        }
        if (s.find(i) != s.end()) f = 0;
    }
    if (f == 1) s.insert(x);
}

//int dp[N][2];
//
//void tdfs(int x, int p) {
//    dp[x][1] = 1;
//    dp[x][0] = 0;
//
//    for (int &i : g[x]) {
//        if (i == p) continue;
//        dp[x][0] += max(dp[i][1], dp[i][0]);
//        dp[x][1] += dp[i][0];
//    }
//}
//
//void backtrack(int x, int p, bool f = true) {
//    if (ans.size() == (k + 1) / 2)
//        return;
//    if (dp[x][1] >= dp[x][0] and f) {
//        ans.push_back(x);
//        for (int &i : g[x]) {
//            if (i == p) continue;
//            backtrack(i, x, false);
//        }
//        return;
//    }
//    for (int &i : g[x]) {
//        if (i == p) continue;
//        backtrack(i, x, true);
//    }
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

//    if (m == n - 1) {
//        tdfs(1, 0);
//        backtrack(1, 0);
//        cout << 1 << "\n";
//        for (int i : ans) cout << i << " ";
//        return 0;
//    }

    d[1] = 1;
    dfs(1);

    k = (k + 1) / 2;
    cout << 1 << "\n";

    for (int i : s) {
        cout << i << " ";
        k--;
        if (!k) break;
    }
    return 0;
}