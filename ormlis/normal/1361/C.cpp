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

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 5e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<ar<int, 2>> a(n);
    range(i, n) range(j, 2) cin >> a[i][j];
    for(int k = 20; k >= 0; --k) {
        range(i, n) range(j, 2) a[i][j] &= (1 << k) - 1;
        vector<vector<int>> g(1<<k);
        range(i, n) range(j, 2) g[a[i][j]].push_back(i * 2 + j);
        vector<int> u(n);
        vector<int> ans;
        function<void(int)> dfs = [&] (int v) {
            while(!g[v].empty()) {
                auto w = g[v].back();
                g[v].pop_back();
                int i = w / 2;
                if (u[i]) continue;
                u[i] = 1;
                int j = w % 2;
                dfs(a[i][j^1]);
                ans.push_back(w ^ 1);
                ans.push_back(w);
            }
        };
        bool bad = false;
        range(i, 1<<k) {
            if (g[i].size() % 2) {
                bad = true;
            }
        }
        if (bad) continue;
        dfs(a[0][0]);
        if (ans.size() == n * 2) {
            cout << k << "\n";
            for(auto &x: ans) cout << x + 1 << " ";
            cout << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}