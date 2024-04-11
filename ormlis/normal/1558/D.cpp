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

const int INFi = 2e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 3e6 + 1;

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

const int maxF = 4e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int T(int n, int k) {
    return C(n + k - 1, k - 1);
}

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }

    int lower_bound(ll x) {
        int r = -1;
        for(int j = 19; j >= 0; --j) {
            int w = 1 << j;
            if (r + w < n && fenw[r + w] < x) {
                r += w;
                x -= fenw[r];
            }
        }
        return r + 1;
    }
} F;
set<int> alive;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> x(m), y(m);
    range(i, m) cin >> x[i] >> y[i];
    set<int> bad;
    vector<int> mem1, mem2;
    for(int j = m - 1; j >= 0; --j) {
        int i = F.lower_bound(y[j] - 1);
        int pos = *alive.lower_bound(i);
        int pos2 = *alive.upper_bound(pos);
        auto it = bad.lower_bound(pos);
        if (it == bad.end() || (*it) >= pos2) {
            bad.insert(pos);
        }
        alive.erase(pos);
        F.upd(i, -1);
        mem1.push_back(pos);
        mem2.push_back(i);
    }
    for(auto &w : mem1)  alive.insert(w);
    for(auto &w : mem2) F.upd(w, 1);
    cout << T(n - 1 - (int)bad.size(), n + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    init();
    F.build(2e5 + 10);
    range(i, 2e5 + 9) {
        F.upd(i + 1, 1);
    }
    range(i, 2e5 + 10) alive.insert(i);
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}