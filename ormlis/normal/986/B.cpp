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
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

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
};


ll inversions(const vector<int> &a) {
    fenwick f;
    f.build(a.size() + 1);
    ll ans = 0;
    int c = 0;
    for(auto &x : a) {
        ans += c - f.get(x);
        f.upd(x, 1);
        c++;
    }
    return ans;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> gen(int n, int ops) {
    vector<int> a(n);
    iota(all(a), 0);
    range(_, ops) {
        int i = rng() % n;
        int j = rng() % n;
        while(i == j) {
            j = rng() % n;
        }
        swap(a[i], a[j]);
    }
    return a;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    ll invs = inversions(a);
    if (n % 2 == invs % 2) {
        cout << "Petr\n";
    } else {
        cout << "Um_nik\n";
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