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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<vector<int>> lists(n);
    vector<int> deg(n);
    vector<bool> deleted(n);

    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;

    auto delete_lists = [&](int v) {
        range(_, k) {
            int u = lists[v].back();
            lists[v].pop_back();
            deleted[u] = true;
            deg[u] = 0;
            deg[v]--;
        }
        if (lists[v].size() >= k) q.push(v);
    };

    auto make_list = [&](int v) {
        assert(deg[v] == 1);
        int cnt = 0;
        for (auto &u : g[v]) {
            if (deleted[u]) continue;
            lists[u].push_back(v);
            if (lists[u].size() == k) q.push(u);
            cnt++;
        }
        assert(cnt <= 1);
    };


    range(i, n) {
        deg[i] = g[i].size();
        if (deg[i] == 1) make_list(i);
    }
    int ans = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (deg[v] == 0) continue;
        ans++;
        delete_lists(v);
        if (deg[v] == 1) make_list(v);
    }
    cout << ans << "\n";
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