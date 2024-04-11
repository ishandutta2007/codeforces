#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n), a(n);
    range(i, n) {
        int x;
        cin >> x;
        a[x - 1].emplace_back(0, i);
    }
    range(i, n) {
        int x;
        cin >> x;
        a[x - 1].emplace_back(1, i);
    }
    range(i, n) {
        if (a[i].size() != 2) {
            cout << "-1\n";
            return;
        }
        int u = a[i][0].second;
        int v = a[i][1].second;
        g[u].emplace_back(v, a[i][0].first == a[i][1].first);
        g[v].emplace_back(u, a[i][0].first == a[i][1].first);
    }
    vector<int> used(n, -1);
    bool bad = false;
    vector<vector<int>> cnt(2);
    function<void(int, int)> dfs = [&](int v, int c) {
        used[v] = c;
        cnt[c].push_back(v);
        for (auto &[u, tt]: g[v]) {
            if (used[u] != -1) {
                if (used[u] != (tt ^ c)) {
                    bad = true;
                    return;
                }
                continue;
            }
            dfs(u, c ^ tt);
            if (bad) return;
        }
    };
    vector<int> ans;
    range(i, n) {
        if (used[i] != -1) continue;
        cnt[0].clear();
        cnt[1].clear();
        dfs(i, 0);
        if (bad) {
            cout << "-1\n";
            return;
        }
        if (cnt[0].size() > cnt[1].size()) swap(cnt[0], cnt[1]);
        for(auto &x: cnt[0]) ans.push_back(x);
    }
    cout << ans.size() << "\n";
    for(auto &x : ans) cout << x + 1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}