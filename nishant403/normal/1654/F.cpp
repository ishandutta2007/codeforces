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

extern const int MOD = 1e9 + 9;
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

const int P = 37;

const int N = (1 << 20) + 10;
string s;
int n;

mod_int pows[N];
vector<mod_int> hash_value[N];

void build(int node, int L, int R)
{
    if (L == R)
    {
        hash_value[node].push_back((s[L] - 'a' + 1));
        return;
    }

    int mid = (L + R) / 2;

    build(node * 2, L, mid);
    build(node * 2 + 1, mid + 1, R);

    int len = (R - L + 1) / 2;

    // Left then Right
    for (int j = 0; j < len; j++)
    {
        hash_value[node].push_back(hash_value[node * 2][j] + hash_value[node * 2 + 1][j] * pows[len]);
    }

    // Right then Left
    for (int j = 0; j < len; j++)
    {
        hash_value[node].push_back(hash_value[node * 2 + 1][j] + hash_value[node * 2][j] * pows[len]);
    }
}

mod_int get_hash(int mask, int length, int node, int L, int R)
{
    if (length == 0)
    {
        return 0;
    }
    else if (L == R)
    {
        return hash_value[node][0];
    }

    int sub_tree_length = (R - L + 1) / 2;

    mod_int res = 0;

    int bit_set = ((mask & sub_tree_length) > 0);

    int new_mask = mask;
    if (bit_set)
        new_mask ^= sub_tree_length;

    if (length >= sub_tree_length)
    {
        res += hash_value[node * 2 + bit_set][new_mask];
        length -= sub_tree_length;

        if (bit_set == 1)
        {
            res += get_hash(new_mask, length, node * 2, L, L + sub_tree_length - 1) * pows[sub_tree_length];
        }
        else
        {
            res += get_hash(new_mask, length, node * 2 + 1, L + sub_tree_length, R) * pows[sub_tree_length];
        }
    }
    else
    {

        if (bit_set == 0)
        {
            res += get_hash(new_mask, length, node * 2, L, L + sub_tree_length - 1);
        }
        else
        {
            res += get_hash(new_mask, length, node * 2 + 1, L + sub_tree_length, R);
        }
    }

    return res;
}

int get_char(int mask, int index)
{
    return s[index ^ mask];
}

mod_int brute_get_hash(int mask, int length)
{
    mod_int res = 0;

    for (int i = 0; i < length; i++)
    {
        res += get_char(mask, i) * pows[i];
    }

    return res;
}

void solve()
{
    cin >> n;
    cin >> s;

    build(1, 0, (1 << n) - 1);

    int best_mask = 0;

    for (int i = 1; i < (1 << n); i++)
    {
        int max_same = 0;
        int L = 1;
        int R = (1 << n);

        while (L <= R)
        {
            int mid = (L + R) / 2;

            if (get_hash(best_mask, mid, 1, 0, (1 << n) - 1) == get_hash(i, mid, 1, 0, (1 << n) - 1))
            {
                max_same = mid;
                L = mid + 1;
            }
            else
            {
                R = mid - 1;
            }
        }

        if (max_same < (1 << n))
        {
            if (get_char(best_mask, max_same) > get_char(i, max_same))
            {
                best_mask = i;
            }
        }
    }

    string t;

    f(i, (1 << n))
    {
        t += get_char(best_mask, i);
    }

    cout << t << '\n';
}

signed main()
{
    pows[0] = 1;

    for (int i = 1; i < N; i++)
    {
        pows[i] = (pows[i - 1] * P);
    }

    fast;
    solve();
}