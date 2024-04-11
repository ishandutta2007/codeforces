#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)
#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 5e4 + 5;
const int LG = 19;

int MD;
int ph = 0;
vector<int> pr;
vector<int> st;

struct Mint {
    int x;
    vector<int> cur;

    Mint(int val = 0) {
        cur.resize(pr.size());
        if (val == 0) {
            x = 0;
            return;
        }
        rep(i, (int) pr.size()) {
            while (val % pr[i] == 0) {
                cur[i]++;
                val /= pr[i];
            }
        }
        x = val % MD;
    }

    int get() {
        int val = x;
        rep(i, (int)pr.size()) {
            assert(cur[i] >= 0);
            rep(_, cur[i]) {
                val = (1ll * val * pr[i]) % MD;
            }
        }
        return val;
    }
};

Mint operator*(const Mint &a, const Mint &b) {
    Mint c(1);
    rep(i, (int) pr.size()) c.cur[i] = a.cur[i] + b.cur[i];
    c.x = (1ll * a.x * b.x) % MD;
    return c;
}

int pw(int a, int b) {
    int r = 1;
    for (; b; b >>= 1, a = (1ll * a * a) % MD) if (b & 1) r = (1ll * r * a) % MD;
    return r;
}

Mint operator/(const Mint &a, const Mint &b) {
    Mint c(1);
    rep(i, (int) pr.size()) c.cur[i] = a.cur[i] - b.cur[i];
    c.x = (1ll * a.x * pw(b.x, ph - 1)) % MD;
    return c;
}

void solve() {
    int n;
    cin >> n >> MD;
    int l, r; cin >> l >> r;
    if (MD == 1) {
        cout << "0\n";
        return;
    }
    {
        ph = MD;
        int t = MD;
        for (int i = 2; 1ll * i * i <= t; ++i) {
            if (t % i) continue;
            pr.push_back(i);
            st.push_back(0);
            ph -= ph / i;
            while (t % i == 0) {
                st.back()++;
                t /= i;
            }
        }
        if (t != 1) {
            ph -= ph / t;
            pr.push_back(t);
            st.push_back(0);
        }
    }
    vector<Mint> fact(n + 1);
    fact[0] = Mint(1);
    for(int i = 1; i <= n; ++i) {
        Mint val(i);
        fact[i] = fact[i - 1] * val;
    }
    int ans = 0;

    auto C = [&] (int N, int K) {
        return fact[N] / (fact[K] * fact[N - K]);
    };

    for(int k = 0; k <= n; ++k) {
        int L = (l + k + 1) / 2;
        int R = (r + k) / 2;
        L = max(L, 0ll);
        R = min(R, k);
        if (L > R) continue;
        int v1 = C(n, k).get();
        ans += (1ll * C(k, L).get() * v1) % MD;
        ans %= MD;
        if (R != k) ans -= (1ll * C(k, R + 1).get() * v1) % MD;
        ans += MD;
        ans %= MD;
    }
    cout << (ans % MD + MD) % MD << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}