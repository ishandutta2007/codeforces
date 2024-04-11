#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

bool good[maxN];
bool used[maxN];
vector<pair<int, int>> g[maxN];
int SZ = 0;

int dfs_sz(int v, int p, vector<ar<int, 4>> &finded) {
    int sz = 1;
    for (auto &[u, i] : g[v]) {
        if (used[i]) continue;
        if (u == p) continue;
        int su = dfs_sz(u, v, finded);
        sz += su;
        if (good[su] && good[SZ - su]) finded.push_back({u, v, i, su});
    }
    return sz;
}

bool check(int v, int s) {
    if (!good[s]) return false;
    if (s == 1) return true;
    SZ = s;
    vector<ar<int, 4>> need_to_check;
    dfs_sz(v, -1, need_to_check);
    for (auto &[u, p, i, su] : need_to_check) {
        used[i] = true;
        if (!check(u, su)) {
            used[i] = false;
            return false;
        }
        bool res = check(p, s - su);
        used[i] = false;
        if (res) return true;
        return false;
    }
    return false;
}

void solve() {
    vector<int> fib(30);
    fib[0] = fib[1] = 1;
    good[1] = true;
    for (int i = 2; i < 30; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] >= maxN) break;
        good[fib[i]] = true;
    }
    int n;
    cin >> n;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v, _);
        g[v].emplace_back(u, _);
    }
    if (check(1, n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}