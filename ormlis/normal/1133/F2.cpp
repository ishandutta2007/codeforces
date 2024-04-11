#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 3e5 + 100;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

vector<int> g[maxN];
vector<pair<int, int>> ans;
int c = 0;
int color[maxN], used[maxN];

void dfs1(int v) {
    color[v] = c;
    for (auto u: g[v]) {
        if (color[u]) continue;
        dfs1(u);
    }
}

void dfs2(int v, int p) {
    ans.emplace_back(v, p);
    used[v] = 1;
    for (auto u: g[v]) {
        if (used[u]) continue;
        dfs2(u, v);
    }
}

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> to1;
    range(i, m) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        if (u == 1) {
            to1.push_back(v);
        } else {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    for (int i = 2; i <= n; ++i)
        if (!color[i]) {
            c++;
            dfs1(i);
        }
    if (c > d || to1.size() < d) {
        cout << "NO\n";
        return;
    }
    int k = d - c;
    vector<int> used_color(c + 1, 0);
    vector<int> ans2;
    for (auto &x: to1) {
        if ((used_color[color[x]] && k)) {
            k--;
            used[x] = 1;
            ans2.push_back(x);
        }
        if (!used_color[color[x]]) {
            used_color[color[x]] = 1;
            ans2.push_back(x);
        }
    }
    for(auto &x: ans2) dfs2(x, 1);
    cout << "YES\n";
    range(i, n - 1) cout << ans[i].first << " " << ans[i].second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}