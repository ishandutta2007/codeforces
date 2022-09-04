#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <ciso646>
#include <cmath>
#include <complex>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop                                                                                                                                                   \
    char nyaa;                                                                                                                                                 \
    cin >> nyaa;
#define rep(i, n) for(int i = 0; i < n; i++)
#define per(i, n) for(int i = n - 1; i >= 0; i--)
#define Rep(i, sta, n) for(int i = sta; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
#define per1(i, n) for(int i = n; i >= 1; i--)
#define Rep1(i, sta, n) for(int i = sta; i <= n; i++)
#define all(v) (v).begin(), (v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}
struct modint {
    ll n;
    modint() : n(0) { ; }
    modint(ll m) : n(m) {
        if (n >= mod)
            n %= mod;
        else if (n < 0)
            n = (n % mod + mod) % mod;
    }
    operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) {
    a.n += b.n;
    if (a.n >= mod) a.n -= mod;
    return a;
}
modint operator-=(modint& a, modint b) {
    a.n -= b.n;
    if (a.n < 0) a.n += mod;
    return a;
}
modint operator*=(modint& a, modint b) {
    a.n = ((ll)a.n * b.n) % mod;
    return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
    if (n == 0) return modint(1);
    modint res = (a * a) ^ (n / 2);
    if (n % 2) res = res * a;
    return res;
}

ll inv(ll a, ll p) { return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p); }
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 2;
modint fact[max_n], factinv[max_n];
void init_f() {
    fact[0] = modint(1);
    for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * modint(i + 1); }
    factinv[max_n - 1] = modint(1) / fact[max_n - 1];
    for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * modint(i + 1); }
}
modint comb(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return fact[a] * factinv[b] * factinv[a - b];
}

template <typename T = long long, const int sz = 5 * 10000000> struct IO {
    char reader[sz], writer[sz];
    char* now, * now2 = writer;
    IO() {
        reader[fread(reader, sizeof(char), sizeof(char) * sz, stdin)];
        now = reader;
    }
    inline T read() {
        while (*now && *now <= 32) now++;
        if (*now == '-') {
            now++;
            T res = 0;
            while ('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            return -res;
        }
        else {
            T res = 0;
            while ('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            return res;
        }
    }
    inline void read(T& res) {
        while (*now && *now <= 32) now++;
        if (*now == '-') {
            now++;
            res = 0;
            while ('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            res = -res;
        }
        else {
            res = 0;
            while ('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
        }
    }
    inline string read_str() {
        string res;
        while (*now and *now != '\n' and *now != ' ') res += *now++;
        now++;
        return res;
    }
    inline void write(T x, char margin = ' ') {
        if (x == 0) {
            putchar('0');
            putchar(margin);
            return;
        }
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        while (x) {
            *now2 = '0' + x % 10;
            now2++;
            x /= 10;
        }
        do {
            now2--;
            putchar(*now2);
        } while (now2 != writer);
        putchar(margin);
    }
    inline void write_str(string s, char margin = ' ') {
        for (auto c : s) putchar(c);
        putchar(margin);
    }
};
IO io;
inline ll read() { return io.read(); }
inline void read(ll& a) { io.read(a); }
inline void write(ll x) { io.write(x); }
inline void write(ll x, char c) { io.write(x, c); }

int dp[61][8];
void solve() {
    ll m;
    read(m);
    rep(i, 61)rep(j, 8)dp[i][j] = 0;
    dp[0][0] = 1;
    rep(i, 60) {
        ll c = 1ll << (59 - i);
        bool b = m & c;
        per(j, 8) {
            if (j < 7) {
                dp[i][j] += dp[i][j+1];
                if (dp[i][j] >= mod)dp[i][j] -= mod;
            }
            int ri = 2 * j + b;
            int le = ri - 8;
            if (le >= 0) {
                dp[i + 1][le] -= dp[i][j];
                if (dp[i + 1][le] < 0)dp[i + 1][le] += mod;
            }
            ri = min(ri, 7);
            dp[i + 1][ri] += dp[i][j];
            if (dp[i + 1][ri] >= mod)dp[i + 1][ri] -= mod;
        }
    }
    int ans = 0;
    rep(j, 8) {
        ans += dp[60][j];
        if (ans >= mod)ans -= mod;
    }
    write(ans, '\n');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(15);
    // init_f();
    /// init();
    // expr();
    ll t;
    read(t);
    rep(i, t) solve();
    return 0;
}