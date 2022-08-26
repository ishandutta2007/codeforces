#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

int n, k;
vector<int> d;
vector<vector<ld>> g;
vector<int> deg;

ld last = 0;

void solve1() {
    last = 0;
    deg.assign(n, 0);
    vector<bool> was(n);
    vector<ld> mn(n, INF);
    vector<int> fr(n, -1);
    mn[0] = 0;
    range(_, n) {
        int x = -1;
        range(j, n) {
            if (was[j]) continue;
            if (mn[j] < mn[x] || x == -1) {
                x = j;
                continue;
            }
            if (mn[j] == mn[x] && fr[j] >= k && j >= k) {
                x = j;
            }
        }
        if (fr[x] != -1) {
            deg[x]++;
            deg[fr[x]]++;
        }
        last += mn[x];
        was[x] = true;
        range(j, n) {
            if (was[j]) continue;
            if (mn[j] > g[x][j]) {
                mn[j] = g[x][j];
                fr[j] = x;
            } else if (mn[j] == g[x][j] && x >= k) {
                fr[j] = x;
            }
        }
    }
}

int K = 10;
bool need = false;

void go(int i) {
    if (i == k) {
        solve1();
        return;
    }
    ld l = 0, r = 110;
    range(_, K) {
        ld mid = (r + l) / 2;
        range(j, n) {
            g[i][j] += mid;
            g[j][i] += mid;
        }
        go(i + 1);
        range(j, n) {
            g[i][j] -= mid;
            g[j][i] -= mid;
        }
        if (deg[i] < d[i]) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (need) r = l;
    range(j, n) {
        g[i][j] += r;
        g[j][i] += r;
    }
    go(i + 1);
    range(j, n) {
        g[i][j] -= r;
        g[j][i] -= r;
    }
    last -= deg[i] * r;
}

void solve() {
    cin >> n >> k;
    d.resize(k);
    range(i, k) cin >> d[i];
    g.resize(n, vector<ld>(n));
    vector<int> ord(n);
    vector<ll> d2(n, n);
    range(i, k) d2[i] = d[i];
    iota(all(ord), 0ll);
    sort(all(ord), [&] (const int &i, const int &j) {
        return make_pair(d2[i], i) < make_pair(d2[j], j);
    });
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int l = 0, r = 0; l < n; l = r) {
        while(r < n && d2[ord[r]] == d2[ord[l]]) r++;
        if (l < k) r = min(r, k);
    }
    vector<int> pos(n);
    range(i, n) pos[ord[i]] = i;
    range(i, n) {
        for (int j = i + 1; j < n; ++j) {
            cin >> g[pos[i]][pos[j]];
            g[pos[j]][pos[i]] = g[pos[i]][pos[j]];
        }
    }
    range(i, k) d[i] = d2[ord[i]];
    need = true;
    go(0);
    range(i, k) d[i]++;
    need = false;
    ld L = last;
    go(0);
    ld R = last;
    cout << round((R + L) / 2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}