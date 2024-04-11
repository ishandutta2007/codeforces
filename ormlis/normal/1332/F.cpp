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
#include <numeric>
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
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

vector<int> g[maxN];
int dp[maxN][3];

// dp[v][0] - -    v  (, . )
// dp[v][1] - -    v  (, . )    v    . 
// dp[v][2] - -    v  (, . )    v    

void dfs(int v, int p) {
    if (p != -1) g[v].erase(find(all(g[v]), p));
    dp[v][0] = dp[v][1] = dp[v][2] = 1;
    for (auto &u : g[v]) {
        dfs(u, v);
        dp[v][1] = mul(dp[v][1], add(mul(dp[u][0], 2), dp[u][2]));
        dp[v][2] = mul(dp[v][2], dp[u][0]);
        dp[v][0] = mul(dp[v][0], add(dp[u][1], dp[u][0]));
    }
    dp[v][0] = add(dp[v][0], dp[v][1]);
    dp[v][0] = sub(dp[v][0], dp[v][2]);
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
    dfs(1, -1);
    cout << sub(dp[1][0], 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}