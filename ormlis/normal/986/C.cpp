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
const int maxN = (1 << 22) + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


struct dsu {
    vector<int> dsu;
    vector<int> rnk;
    int n;
    ll cnt;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        cnt = 0;
        dsu.resize(n);
        rnk.resize(n, 1);
        range(i, n)dsu[i] = i;
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (a == b) return false;
        if (rnk[a] > rnk[b]) swap(a, b);
        rnk[b] += rnk[a];
        dsu[a] = b;
        cnt++;
        return true;
    }
} D;


int n;
int have[maxN];
bool was[maxN];

void solve() {
    cin >> n;
    int m;
    cin >> m;
    range(i, (1 << n)) have[i] = -1;
    vector<int> a(m);
    range(_, m) {
        int x;
        cin >> x;
        a[_] = x;
        have[x] = x;
    }
    range(mask, 1 << n) {
        if (have[mask] == -1) continue;
        range(i, n) {
            if (mask & (1 << i)) continue;
            if (have[mask ^ (1 << i)] == -1) have[mask ^ (1 << i)] = have[mask];
        }
    }
    D.build(1 << n);
    for (auto &mask1 : a) {
        int mask2 = ((1 << n) - 1) ^mask1;
        if (have[mask2] == -1) continue;
        D.unio(mask1, have[mask2]);
        was[mask2] = true;
    }
    for (int mask = (1 << n) - 1; mask >= 0; --mask) {
        if (!was[mask]) continue;
        range(i, n) {
            if (mask & (1 << i)) {
                was[mask ^ (1 << i)] = true;
                if (have[mask ^ (1 << i)] != -1) D.unio(have[mask], have[mask ^ (1 << i)]);
            }
        }
    }
    cout << m - D.cnt << '\n';
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