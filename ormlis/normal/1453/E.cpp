#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN];
int mx = 0;

int dfs(int v, int p) {
    vector<int> kek;
    for (auto &u : g[v]) {
        if (u == p) continue;
        int c = dfs(u, v) + 1;
        kek.push_back(c);
    }
    if (kek.empty()) return 0;
    sort(all(kek));
    mx = max(mx, kek.back());
    if (kek.size() > 1) {
        if (p != -1) mx = max(mx, kek.back() + 1);
        else mx = max(mx, kek[(int)kek.size() - 2] + 1);
    }
    return kek[0];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) g[i].clear();
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mx = 0;
    dfs(1, -1);
    cout << mx << '\n';
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