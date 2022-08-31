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

extern const int MOD = 1e9 + 7;
using mod_int = _m_int<MOD>;

#define int long long

const int LOG_K = 60;

struct xor_basis
{
    int basis[LOG_K], sz;
    bool containBit[LOG_K];

    void insertVector(int mask)
    {
        for (int i = LOG_K - 1; i >= 0; i--)
        {
            if ((mask & 1LL << i) == 0)
                continue;

            if (!basis[i])
            {
                basis[i] = mask;

                for (int j = 0; j < LOG_K; j++)
                {
                    if ((mask >> j) & 1)
                    {
                        containBit[j] = true;
                    }
                }

                sz++;

                return;
            }

            mask ^= basis[i];
        }
    }

    // Find kth greatest xor of a subset with given mask
    int query(int k, int mask)
    {
        int tot = 1 << sz;
        for (int i = LOG_K - 1; i >= 0; i--)
            if (basis[i])
            {
                int low = tot / 2;

                if ((low < k && (mask & 1LL << i) == 0) ||
                    (low >= k && (mask & 1LL << i) > 0))
                    mask ^= basis[i];

                if (low < k)
                    k -= low;

                tot /= 2;
            }

        return mask;
    }
};

const int N = 2e5 + 10;
int n, m;
vector<pair<int, int>> g[N];

xor_basis cycles;

void input()
{
    cin >> n >> m;

    int u, v, w;

    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}

int pref_xor[N];
mod_int bitCount[LOG_K][2];
int vis[N];

void dfs(int node, int par = -1)
{
    // pref_xor[node] is already calculated
    vis[node] = 1;

    for (int j = 0; j < LOG_K; j++)
    {
        bitCount[j][(pref_xor[node] >> j) & 1]++;
    }

    for (auto [v, w] : g[node])
    {
        if (v == par)
            continue;

        if (vis[v])
        {
            // add cycle
            cycles.insertVector(pref_xor[node] ^ pref_xor[v] ^ w);
        }
        else
        {
            pref_xor[v] = pref_xor[node] ^ w;
            dfs(v, node);
        }
    }
}

const mod_int two = 2;

void solve()
{
    input();

    mod_int res = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cycles = *new xor_basis();

            for (int j = 0; j < LOG_K; j++)
            {
                bitCount[j][0] = bitCount[j][1] = 0;
            }

            dfs(i);

            mod_int nodes = (bitCount[0][0] + bitCount[0][1]);
            mod_int paths = (nodes * (nodes - 1)) / 2;

            for (int j = 0; j < LOG_K; j++)
            {
                mod_int count = 0;

                if (cycles.containBit[j])
                {
                    count += two.pow(cycles.sz - 1) * paths;
                }
                else
                {
                    count += bitCount[j][0] * bitCount[j][1] * two.pow(cycles.sz);
                }

                res += count * two.pow(j);
            }
        }
    }

    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}