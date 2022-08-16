#include <bits/stdc++.h>
using namespace std;

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

#define int long long
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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define precise(x) fixed << setprecision(x)

const int N = 2e5 + 20;

vector<pair<int, pii>> g[N];
vector<int> lprime(N, -1);
vector<int> facts[N];

vector<int> factors(int num)
{
    vector<int> res;

    while (num > 1)
    {
        res.pb(lprime[num]);
        num /= lprime[num];
    }

    return res;
}

mod_int sum = 0;

int powers[N];
int max_powers[N];

void dfs(int node, int par = -1, mod_int val = 1)
{
    sum += val;

    for (auto x : g[node])
    {
        if (x.F != par)
        {
            // add to the ratio

            // (node / x.F) = (x / y)
            // (x.F) = (node * y) / x

            // remove powers for y and add for x

            for (auto z : facts[x.S.S])
            {
                powers[z]--;
            }

            for (auto z : facts[x.S.F])
            {
                powers[z]++;
                max_powers[z] = max(max_powers[z], powers[z]);
            }

            dfs(x.F, node, val * (x.S.S) / x.S.F);

            for (auto z : facts[x.S.S])
            {
                powers[z]++;
            }

            for (auto z : facts[x.S.F])
            {
                powers[z]--;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    int u, v, x, y;

    f(i, n - 1)
    {
        cin >> u >> v >> x >> y;

        int gc = __gcd(x, y);
        x /= gc;
        y /= gc;

        g[u].pb({v, {x, y}});
        g[v].pb({u, {y, x}});
    }

    dfs(1);

    mod_int normalize = 1;

    for (int i = 1; i <= n; i++)
    {
        if (max_powers[i] > 0)
            normalize *= ((mod_int)i).pow(max_powers[i]);
    }

    cout << (sum * normalize) << '\n';

    sum = 0;

    for (int i = 1; i <= n; i++)
        g[i].clear();

    for (int i = 0; i <= n; i++)
    {
        powers[i] = 0;
        max_powers[i] = 0;
    }
}

signed main()
{

    for (int i = 2; i < N; i++)
    {
        if (lprime[i] == -1)
        {
            for (int j = i; j < N; j += i)
            {
                lprime[j] = i;
            }
        }
    }

    for (int i = 2; i < N; i++)
    {
        facts[i] = factors(i);
    }

    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}