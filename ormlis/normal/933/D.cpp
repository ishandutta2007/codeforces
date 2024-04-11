#pragma GCC optimize("O3")
#pragma GCC target("avx2")
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
const int maxN = 100 + 5;
const int LG = 30;

// source:
template<int32_t MOD>
struct modint {
    int32_t value;

    modint() = default;

    modint(int32_t value_) : value(value_) {}

    inline modint<MOD> operator+(modint<MOD> other) const {
        int32_t c = this->value + other.value;
        return modint<MOD>(c >= MOD ? c - MOD : c);
    }

    inline modint<MOD> operator-(modint<MOD> other) const {
        int32_t c = this->value - other.value;
        return modint<MOD>(c < 0 ? c + MOD : c);
    }

    inline modint<MOD> operator*(modint<MOD> other) const {
        int32_t c = (int64_t) this->value * other.value % MOD;
        return modint<MOD>(c < 0 ? c + MOD : c);
    }

    inline modint<MOD> &operator+=(modint<MOD> other) {
        this->value += other.value;
        if (this->value >= MOD) this->value -= MOD;
        return *this;
    }

    inline modint<MOD> &operator-=(modint<MOD> other) {
        this->value -= other.value;
        if (this->value < 0) this->value += MOD;
        return *this;
    }

    inline modint<MOD> &operator*=(modint<MOD> other) {
        this->value = (int64_t) this->value * other.value % MOD;
        if (this->value < 0) this->value += MOD;
        return *this;
    }

    inline modint<MOD> operator-() const {
        return modint<MOD>(this->value ? MOD - this->value : 0);
    }

    modint<MOD> pow(uint64_t k) const {
        modint<MOD> x = *this, y = 1;
        for (; k; k >>= 1) {
            if (k & 1) y *= x;
            x *= x;
        }
        return y;
    }

    modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
    inline modint<MOD> operator/(modint<MOD> other) const { return *this * other.inv(); }

    inline modint<MOD> operator/=(modint<MOD> other) { return *this *= other.inv(); }

    inline bool operator==(modint<MOD> other) const { return value == other.value; }

    inline bool operator!=(modint<MOD> other) const { return value != other.value; }

    inline bool operator<(modint<MOD> other) const { return value < other.value; }

    inline bool operator>(modint<MOD> other) const { return value > other.value; }
};

template<int32_t MOD>
modint<MOD> operator*(int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }

template<int32_t MOD>
modint<MOD> operator*(int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }

template<int32_t MOD>
ostream &operator<<(ostream &out, modint<MOD> n) { return out << n.value; }

const int mod = 1e9 + 7;
using mint = modint<mod>;

//generates the polynomial explicitely
vector<mint> Lagrange(const vector<mint> &x, vector<mint> &y) {
    int n = x.size();
    vector<mint> ans(n, 0);
    vector<mint> all1(n + 1, 0); //(x - x0) * (x - x1) * ... * (x - x(n-1))
    all1[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = n; j >= 0; j--) {
            all1[j] *= -x[i];
            if (j) all1[j] += all1[j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        vector<mint> up(n); //all / (x - xi)
        mint rem = all1[n];
        for (int j = n - 1; j >= 0; --j) {
            up[j] = rem;
            rem = all1[j] + rem * x[i];
        }
        mint down = 1;
        for (int j = 0; j < n; j++) if (i != j) down *= x[i] - x[j];
        up.resize(n);
        down = down.inv() * y[i];
        for (int j = 0; j < n; j++) ans[j] += up[j] * down;
    }
    while (!ans.empty() && ans.back() == 0) ans.pop_back();
    return ans;
}


void solve() {
    ll m;
    cin >> m;
    vector<mint> polk2, polk1;
    {
        vector<mint> x, y1, y2;
        mint cur = 0, cur1 = 0;
        for (int i = 0; i < 10; ++i) {
            x.emplace_back(i);
            cur += i * i;
            cur1 += i;
            y1.push_back(cur1);
            y2.push_back(cur);
        }
        polk1 = Lagrange(x, y1);
        polk2 = Lagrange(x, y2);
    }
    mint mm = m % mod;
    auto sum = [&](mint x) {
        mint res = 0;
        mint t = 1;
        rep(i, polk1.size()) {
            res += t * polk1[i];
            t *= x;
        }
        t = 1;
        rep(i, polk2.size()) {
            res += t * polk2[i];
            t *= x;
        }
        return res;
    };

    auto g = [&](ll to) {
        if (to > m) return mint(0);
        mint d = to % mod;
        mint res = (mm - d + 1) * (d - d * d);
        res += sum(mm);
        if (to != 0) res -= sum(d - 1);
        res /= 2;
        return res;
    };

    vector<ll> vals;
    for (ll i = 0; i * i <= m; ++i) {
        vals.push_back(1ll * i * i);
    }
    int sz = vals.size();
    vector<vector<mint>> polys(sz);
    vector<mint> xx;
    for(int i = 1; i < 5; ++i) xx.emplace_back(i);
    vector<vector<mint>> yy(sz, vector<mint> (4));
    int JJ = 0;
    for(auto &x : xx) {
        mint cur = 0;
        ll v = x.value;
        rep(i, sz) {
            cur += g(v + vals[i]);
            yy[i][JJ] = cur;
        }
        JJ++;
    }
    rep(i, sz) {
        polys[i] = Lagrange(xx, yy[i]);
    }
    mint answer = 0;
    int R = (int)vals.size() - 1;
    for(ll x2 : vals) {
        if (x2 == 0) continue;
        while(R >= 0 && vals[R] + x2 > m) R--;
        if (R == -1) break;
        mint x = x2 % mod;
        mint t = 1;
        rep(i, (int)polys[R].size()) {
            answer += t * polys[R][i];
            t *= x;
        }
    }
    answer *= 4;
    answer += g(0);
    cout << answer << '\n';
}

int main() {
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