#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int p[maxN], h[maxN], up[maxN], upk[maxN];
vector<int> g[maxN];
int can[maxN];

int k;

vector<int> current;

void dfsh(int v) {
    if (g[v].empty()) {
        upk[v] = current[max(0, (int) current.size() - k)];
    }
    current.push_back(v);
    for (auto u: g[v]) {
        h[u] = h[v] + 1;
        dfsh(u);
    }
    current.pop_back();
}

int dp[maxN];

void dfs(int v) {
    for (auto u: g[v]) {
        dfs(u);
        dp[v] = max(dp[v], dp[u]);
    }
    dp[v] += can[v];
}

void solve() {
    int n;
    cin >> n >> k;
    for (int i = 2; i <= n; ++i) {
        int pr;
        cin >> pr;
        g[pr].push_back(i);
        p[i] = pr;
    }
    dfsh(1);
    vector<int> lists;
    for (int i = 2; i <= n; ++i) {
        if (g[i].empty()) {
            lists.push_back(i);
        }
    }
    sort(all(lists), [](int &a, int &b) {
        return h[a] < h[b];
    });
    for (int i = 1; i <= n; ++i) up[i] = i;
    for (auto x: lists) {
        int cur = up[upk[x]];
        can[cur]++;
        while (~x && h[up[x]] > h[cur] && x != cur) {
            up[x] = cur;
            x = p[x];
        }
    }
    dfs(1);
    cout << dp[1];
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