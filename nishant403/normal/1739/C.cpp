#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define pb push_back
#define S second
#define F first
#define f(i, n) for (int i = 0; i < n; i++)
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define vi vector<int>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

template <const int &MOD>
struct _m_int
{
    int val;

    _m_int(int64_t v = 0)
    {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }

    static int mod_inv(int a, int m = MOD)
    {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;

        while (r != 0)
        {
            int q = g / r;
            g %= r;
            swap(g, r);
            x -= q * y;
            swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const { return val; }
    explicit operator int64_t() const { return val; }

    _m_int &operator+=(const _m_int &other)
    {
        val -= MOD - other.val;
        if (val < 0)
            val += MOD;
        return *this;
    }

    _m_int &operator-=(const _m_int &other)
    {
        val -= other.val;
        if (val < 0)
            val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD)
    {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned)x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a"(quot), "=d"(rem)
            : "d"(x_high), "a"(x_low), "r"(m));
        return rem;
    }

    _m_int &operator*=(const _m_int &other)
    {
        val = fast_mod((uint64_t)val * other.val);
        return *this;
    }

    _m_int &operator/=(const _m_int &other)
    {
        return *this *= other.inv();
    }

    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }

    _m_int &operator++()
    {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_int &operator--()
    {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_int operator++(int)
    {
        _m_int before = *this;
        ++*this;
        return before;
    }
    _m_int operator--(int)
    {
        _m_int before = *this;
        --*this;
        return before;
    }

    _m_int operator-() const
    {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const _m_int &other) const { return val == other.val; }
    bool operator!=(const _m_int &other) const { return val != other.val; }

    _m_int inv() const
    {
        return mod_inv(val);
    }

    _m_int pow(int64_t p) const
    {
        if (p < 0)
            return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0)
        {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream &operator<<(ostream &os, const _m_int &m)
    {
        return os << m.val;
    }
};

extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;

const int N = 100;
mod_int dp[N][3];

mod_int fact[N];
mod_int ifact[N];

void init()
{
    fact[0] = 1;

    for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i);

    ifact[N - 1] = fact[N - 1].inv();

    for (int i = N - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1));
}

mod_int ncr(int n, int r)
{
    if (r > n)
        return 0;

    return fact[n] * ifact[r] * ifact[n - r];
}

void solve()
{
    int n;
    cin >> n;
    n /= 2;
    cout << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2] << '\n';
}

signed main()
{
    init();

    dp[1][0] = 1;
    dp[1][2] = 1;

    for (int i = 2; i < N; i++)
    {
        dp[i][0] = ncr(i + i - 1, i) + dp[i - 1][1];
        dp[i][1] = ncr(i + i, i) - (dp[i][0] + 1);
        dp[i][2] = 1;
    }

    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}