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
const int maxN = 1e6+1;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

vector<int> g[maxN];
int dp[maxN], hdp[maxN];
int k;
void dfs(int v, int p) {
    if (g[v].size() == 1) {
        dp[v] = 1;
        hdp[v] = 0;
        return;
    }
    vector<pair<int, int>> toans;
    for(auto u: g[v]) {
        if (u == p) continue;
        dfs(u, v);
        if (dp[u] != 0) {
            toans.emplace_back(hdp[u], dp[u]);
        }
    }
    if (!toans.empty()) {
        sort(rall(toans));
        dp[v] = toans[0].second;
        int cur = toans[0].first;
        hdp[v] = cur + 1;
        for(int i = 1; i < toans.size(); ++i) {
            if (cur + toans[i].first + 2 <= k) {
                dp[v] += toans[i].second - 1;
                cur = max(cur, toans[i].first);
            } else {
                hdp[v] = min(cur + 1, hdp[v]);
                dp[v] += toans[i].second;
                cur = toans[i].first;
            }
        }
        hdp[v] = min(cur + 1, hdp[v]);
    }
}

void solve() {
    int n; cin >> n >> k;
    range(i, n - 1) {
        int u, v; cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; ++i) {
        if (g[i].size() > 1) {
            dfs(i, -1);
            cout << dp[i];
            break;
        }
    }
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