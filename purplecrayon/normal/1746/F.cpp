#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

    // let D be a fixed reasonably small constant
    //
    // let's say k is fixed
    // for each number, generate a random D vector in Z_k, check if the sum is the 0 vector
    //
    // let m = 1e9
    // because k is not fixed, generate a random D vector in Z_m, just sum them up with longs and mod at the end
    // complexity is O((n + q) * D * log) => D = ~30
    //      log should be pretty fast (fenwick)
    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

const int D = 30, M = 1e9;
struct vec {
    ll a[D];
    vec() {
        memset(a, 0, sizeof(a));
    }
    void make_rand() {
        // generates random vec
        for (int i = 0; i < D; i++) a[i] = rnd(0, M);
    }
    vec& operator += (const vec& o) {
        for (int i = 0; i < D; i++) a[i] += o.a[i];
        return *this;
    }
    friend vec operator + (const vec& a, const vec& b) {
        vec ans;
        for (int i = 0; i < D; i++) ans.a[i] = a.a[i] + b.a[i];
        return ans;
    }
    friend vec operator - (const vec& a, const vec& b) {
        vec ans;
        for (int i = 0; i < D; i++) ans.a[i] = a.a[i] - b.a[i];
        return ans;
    }
    bool is_z(int k) {
        bool ans = 0;
        for (int i = 0; i < D; i++) ans |= a[i] % k;
        return !ans;
    }
};

template<class T>
struct FT {
    vector<T> bit;
    FT(int n) : bit(n) {}
    FT(){}
    void upd(int i, T x) {
        for (; i < sz(bit); i |= i+1) bit[i] += x;
    }
    T qry(int r) {
        T ans = T();
        for (++r; r > 0; r &= r-1) ans += bit[r-1];
        return ans;
    }
    T qry(int l, int r) {
        return qry(r)-qry(l-1);
    }
};

void solve() {

    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto& x : a) cin >> x;

    map<int, vec> store;
    auto get_vec = [&](int x) {
        if (store.count(x)) return store[x];
        vec new_vec = vec(); new_vec.make_rand();
        return store[x] = new_vec;
    };

    FT<vec> bit(n);
    for (int i = 0; i < n; i++) bit.upd(i, get_vec(a[i]));

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x, --i;
            bit.upd(i, get_vec(x) - get_vec(a[i]));
            a[i] = x;
        } else {
            int l, r, k; cin >> l >> r >> k, --l, --r;
            cout << (bit.qry(l, r).is_z(k) ? "YES\n" : "NO\n");
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}