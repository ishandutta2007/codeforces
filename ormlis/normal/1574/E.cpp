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

struct kek_struct {
    vector<int> c[2];
    int cnt1 = 0, cnt0 = 0;

    void init(int n) {
        c[0].resize(n, 0);
        c[1].resize(n, 0);
    }

    void add(int x, int y, int t) {
        if (c[1][x] && c[0][x]) {
            cnt0--;
        } else if (c[1][x] || c[0][x]) {
            cnt1--;
        }
        c[t ^ (y & 1)][x]++;
        if (c[1][x] && c[0][x]) {
            cnt0++;
        } else if (c[1][x] || c[0][x]) {
            cnt1++;
        }
        assert(cnt0 >= 0);
        assert(cnt1 >= 0);
    }

    void del(int x, int y, int t) {
        if (c[1][x] && c[0][x]) {
            cnt0--;
        } else if (c[1][x] || c[0][x]) {
            cnt1--;
        }
        c[t ^ (y & 1)][x]--;
        if (c[1][x] && c[0][x]) {
            cnt0++;
        } else if (c[1][x] || c[0][x]) {
            cnt1++;
        }
        assert(cnt0 >= 0);
        assert(cnt1 >= 0);
    }
};


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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    kek_struct cols, rows;
    cols.init(n + 1);
    rows.init(m + 1);
    map<pair<int, int>, int> to;
    ar<int, 2> cnt2 = {0, 0};
    range(_, k) {
        int x, y, t;
        cin >> x >> y >> t;
        if (t == -1) {
            if (to.count({x, y})) {
                t = to[{x, y}];
                to.erase({x, y});
                cols.del(x, y, t);
                rows.del(y, x, t);
                cnt2[(x ^ y ^ t) & 1]--;
            }
        } else {
            if (to.count({x, y})) {
                int t2 = to[{x, y}];
                cols.del(x, y, t2);
                rows.del(y, x, t2);
                cnt2[(x ^ y ^ t2) & 1]--;
            }
            to[{x, y}] = t;
            cols.add(x, y, t);
            rows.add(y, x, t);
            cnt2[(x ^ y ^ t) & 1]++;
        }
        if (cols.cnt0 && rows.cnt0) {
            cout << "0\n";
            continue;
        }
        if (cols.cnt0) {
            cout << binpow(2, m - rows.cnt1) << '\n';
        } else if (rows.cnt0) {
            cout << binpow(2, n - cols.cnt1) << '\n';
        } else {
            int answer = add(binpow(2, n - cols.cnt1), binpow(2, m - rows.cnt1));
            if (cnt2[0] == 0) answer = sub(answer, 1);
            if (cnt2[1] == 0) answer = sub(answer, 1);
            cout << answer << '\n';
        }
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