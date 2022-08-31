#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef __int128 i128;

const ll INF = 2e18;
const int INFi = 1e9 + 5;
const int maxN = 751 + 1;
const int md = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int m = 1 << n;
    vector<vector<int>> g(m);
    range(i, n * (m / 2)) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> p(m, -3);
    vector<int> p1(m, -1);
    p[0] = 0;
    p1[0] = 0;
    queue<int> q;
    range(i, n) {
        p[g[0][i]] = (1 << i);
        p1[(1 << i)] = g[0][i];
        q.push(g[0][i]);
    }
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        int m1 = -1, m2 = -1;
        for(auto &u : g[v]) {
            if (p[u] < -1) {
                p[u]++;
                if (p[u] == -1) {
                    q.push(u);
                }
            }
            if (p[u] > -1) {
                if (m1 == -1) m1 = p[u];
                else if (m2 == -1) m2 = p[u];
            }
        }
        if (p[v] == -1) {
            int m3 = m1 ^ m2;
            int mask = (m1 & m3)^m1;
            if (p1[mask] != -1) mask ^= m3;
            assert(p1[mask] == -1);
            p1[mask] = v;
            p[v] = mask;
        }
    }
    range(i, m) cout << p1[i] << ' ';
    cout << '\n';
    if (__builtin_popcount(n) != 1) {
        cout << "-1\n";
        return;
    }
    range(i, m) {
        int t = 0;
        range(w, n) {
            if (p[i] & (1 << w)) t ^= w;
        }
        cout << t << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}