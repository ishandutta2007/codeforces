#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e6 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

map<int, int> g[maxN];
int R = 1;

void add(ar<int, 10> &w, int n) {
    int v = 0;
    range(i, n) {
        int c = w[i];
        if (!g[v].count(c)) {
            g[v][c] = R++;
        }
        v = g[v][c];
    }
}

int go(int v, int c) {
    if (v == -1) return -1;
    if (!g[v].count(c)) return -1;
    return g[v][c];
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    range(i, n) {
        int c;
        cin >> c;
        a[i].resize(c);
        range(j, c) cin >> a[i][j];
        reverse(all(a[i]));
    }
    int m;
    cin >> m;
    range(i, m) {
        ar<int, 10> w;
        range(j, 10) w[j] = 0;
        range(j, n) {
            cin >> w[j];
            w[j] = (int) a[j].size() - w[j];
        }
        add(w, n);
    }
    ar<int, 10> cur;
    range(j, 10) cur[j] = 0;
    ll ans = 0;
    ar<int, 10> ansc;
    function<void(int, int, ll, ll)> rec = [&](int i, int v, ll s, ll p) {
        if (i == n) {
            if (ans >= s || v != -1) return;
            ans = s;
            ansc = cur;
            return;
        }
        range(k, (int) a[i].size()) {
            if (1ll * p * (k + 1) - 1 > m) break;
            cur[i] = k;
            int t = go(v, k);
            rec(i + 1, t, s + a[i][k], 1ll * p * (k + 1));
            if (t == -1) break;
        }
    };
    rec(0, 0, 0, 1);
    range(i, n) {
        cout << (int) a[i].size() - ansc[i] << ' ';
    }
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