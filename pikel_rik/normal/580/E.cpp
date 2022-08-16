#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

const int M = 1618344671;
const int N = 1e5 + 5;

ll h[N], pref[N];
void precomp() {
    h[0] = M;
    for (int i = 1; i < N; i++) {
        h[i] = M * h[i - 1] % mod;
    }
    pref[0] = M;
    for (int i = 1; i < N; i++) {
        pref[i] = (pref[i - 1] + h[i]) % mod;
    }
}

ll get(int l, int r) {
    if (!l)
        return pref[r];
    return ((pref[r] - pref[l - 1]) % mod + mod) % mod;
}

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

template <typename T> class SegmentTree {
public:
    int n;
    T e;
    vector<T> t, lazy;
    function<T(const T&, const T&)> f;
    SegmentTree() : n(), t(), f(), lazy(), e() {}

    template <typename U> void build(const U& arr, int _n, T _e = T(), function<T(const T&, const T&)> func = plus<T>()) {
        e = _e; n = _n;
        f = move(func);
        t.resize(4 * n + 4);
        lazy.resize(4 * n + 4);

        function<void(int, int, int)> build = [&] (int i, int l, int r) {
            if (l == r) {
                t[i] = T(arr[l]);
                return;
            }

            int mid = l + (r - l) / 2;
            build(i << 1, l, mid);
            build(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        build(1, 0, n - 1);
    }

    void push (int x, int l, int r) {
        if (lazy[x]) {
            int mid = l + (r - l) / 2;
            t[x << 1] = get(l, mid) * lazy[x] % mod;
            t[x << 1 | 1] = get(mid + 1, r) * lazy[x] % mod;
            lazy[x << 1] = lazy[x << 1 | 1] = lazy[x];
            lazy[x] = 0;
        }
    }

    template <typename U> void update(int idx, U val) {
        function<void(int, int, int)> update = [&](int i, int l, int r) {
            if (l == r) {
                t[i] = T(val);
                return;
            }
            push(i, l, r);
            int mid = l + (r - l) / 2;
            if (idx <= mid)
                update(i << 1, l, mid);
            else update(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        update(1, 0, n - 1);
    }

    template <typename U> void update(int ql, int qr, U val) {
        function<void(int, int, int)> update = [&](int i, int l, int r) {
            if (ql > r or qr < l)
                return;
            if (ql <= l and r <= qr) {
                t[i] = get(l, r) * val % mod;
                lazy[i] = val;
                return;
            }
            push(i, l, r);
            int mid = l + (r - l) / 2;
            update(i << 1, l, mid);
            update(i << 1 | 1, mid + 1, r);

            t[i] = f(t[i << 1], t[i << 1 | 1]);
        };
        update(1, 0, n - 1);
    }

    T query(int ql, int qr) {
        function<T(int, int, int)> query = [&](int i, int l, int r) {
            if (ql > r or qr < l)
                return e;
            if (ql <= l and r <= qr)
                return t[i];
            push(i, l, r);
            int mid = l + (r - l) / 2;
            T x = query(i << 1, l, mid), y = query(i << 1 | 1, mid + 1, r);
            return f(x, y);
        };
        return query(1, 0, n - 1);
    }
};

int n, m, k;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    precomp();
    cin >> n >> m >> k;
    cin >> s;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = h[i] * s[i] % mod;
    }
    SegmentTree<ll> st;
    st.build(a, n);

    m += k;
    while (m--) {
        int t, l, r, c;
        cin >> t >> l >> r >> c; --l; --r;

        if (t == 1)
            st.update(l, r, c + 48);
        else {
            ll val1 = st.query(l, r - c) % mod;
            ll val2 = st.query(l + c, r) % mod;
            val2 = val2 * modinv(h[c - 1]) % mod;
            if (val1 == val2)
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}