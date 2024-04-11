#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];

vector<pair<int, int>> ans;

void dfs(int v, int need_to_back, int t, int p = -1) {
    ans.emplace_back(v, t);
    int sz = g[v].size();
    if (sz == 1 && p != -1) {
        if (t == need_to_back) return;
        ans.emplace_back(v, need_to_back);
        return;
    }
    if (need_to_back < sz) {
        range(i, sz) {
            if (g[v][i] == p) continue;
            if (t >= sz) {
                ans.emplace_back(v, 0);
                t = 0;
            }
            dfs(g[v][i], t, t + 1, v);
            ans.emplace_back(v, t + 1);
            t++;
        }
    } else {
        if (t > need_to_back - sz + 1) {
            ans.emplace_back(v, need_to_back - sz + 1);
            t = need_to_back - sz + 1;
        }
        range(i, sz) {
            if (g[v][i] == p) continue;
            dfs(g[v][i], t, t + 1, v);
            ans.emplace_back(v, t + 1);
            t++;
        }
    }
    if (t != need_to_back) {
        ans.emplace_back(v, need_to_back);
    }
}

void solve() {
    int n;
    cin >> n;
    range(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, g[1].size(), 0);
    cout << ans.size() << '\n';
    for(auto &p: ans) cout << p.first << " " << p.second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}