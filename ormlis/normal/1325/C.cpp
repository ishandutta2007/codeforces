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
const int maxN = 1e6 + 1;
ll md = 1000000007;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<pair<int, int>> g[maxN];

void solve() {
    int n;
    cin >> n;
    range(i, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    if (n == 2) {
        cout << 0;
        return;
    }
    vector<int> d;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            d.push_back(g[i][0].second);
        }
    }
    vector<int> ans(n-1, -1);
    range(i, min(3, (int) d.size())) {
        ans[d[i]] = i;
    }
    int nxt = min(3, (int) d.size());
    range(i, n) {
        if (ans[i] == -1) {
            ans[i] = nxt;
            nxt++;
        }
    }
    range(i, n-1) cout << ans[i] << "\n";
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