#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<const int &MOD>
struct _m_int {
    int val;

    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}

    static int inv_mod(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }

    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }

    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }

    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }

    _m_int inv() const {
        return inv_mod(val);
    }

    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};

extern const int MOD = 1e9 + 7;
using mod_int = _m_int<MOD>;


/**
 * Author:
 * Description: Linear-time SA+LCP+Tree
 */
namespace SuffixArray {

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define per(i,a,b) for(int i = (b)-1; i >= (a); --i)

// TODO: adjust this constant as needed.
const int N = 1e6 + 5;

int sa[N],rk[N],ht[N];
bool t[N<<1];

bool islms(const int i,const bool *t) { /// start-hash
    return i>0&&t[i]&&!t[i - 1];
} /// end-hash

template<class T>
inline void sort(T s,int *sa,const int len,const int sz,const int sigma,
                    bool *t,int *b,int *cb,int *p) { /// start-hash
    memset(b,0,sizeof(int)*sigma);
    memset(sa,-1,sizeof(int)*len);
    rep(i,0,len) b[(int)s[i]]++;
    cb[0]=b[0];
    rep(i,1,sigma) cb[i]=cb[i-1]+b[i];
    per(i,0,sz) sa[--cb[(int)s[p[i]]]]=p[i];
    rep(i,1,sigma) cb[i]=cb[i-1]+b[i-1];
    rep(i,0,len) if (sa[i]>0&&!t[sa[i]-1]) sa[cb[(int)s[sa[i]-1]]++]=sa[i]-1;
    cb[0]=b[0];
    rep(i,1,sigma) cb[i]=cb[i-1]+b[i];
    per(i,0,len) if (sa[i]>0&&t[sa[i]-1]) sa[--cb[(int)s[sa[i]-1]]]=sa[i]-1;
} /// end-hash

template<class T>
inline void sais(T s,int *sa,const int len,bool *t,int *b,int *b1,
                const int sigma) { /// start-hash
    int p=-1,*cb=b+sigma;
    t[len-1]=1;
    per(i,0,len-1) t[i]=s[i]<s[i+1]||(s[i]==s[i+1]&&t[i+1]);
    int sz=0,cnt=0;
    rep(i,1,len) if (t[i]&&!t[i-1]) b1[sz++]=i;
    sort(s,sa,len,sz,sigma,t,b,cb,b1);
    sz=0;
    rep(i,0,len) if (islms(sa[i],t)) sa[sz++]=sa[i];
    rep(i,sz,len) sa[i]=-1;
    rep(i,0,sz) {
        int x=sa[i];
        rep(j,0,len) {
            if (p==-1||s[x+j]!=s[p+j]||t[x+j]!=t[p+j]) {
                cnt++; p=x;
                break;
            } else if (j>0&&(islms(x+j,t)||islms(p+j,t))) {
                break;
            }
        }
        sa[sz+(x>>=1)]=cnt-1;
    }
    for (int i=len-1,j=len-1;i>=sz;i--) if (sa[i]>=0) sa[j--]=sa[i];
    int *s1=sa+len-sz,*b2=b1+sz;
    if (cnt<sz) sais(s1,sa,sz,t+len,b,b1+sz,cnt);
    else rep(i,0,sz) sa[s1[i]]=i;
    rep(i,0,sz) b2[i]=b1[sa[i]];
    sort(s,sa,len,sz,sigma,t,b,cb,b2);
} /// end-hash

template<class T>
inline void getHeight(T s,int n) { /// start-hash
    rep(i,1,n+1) rk[sa[i]]=i;
    int j=0,k=0;
    for (int i=0;i<n;ht[rk[i++]]=k)
        for (k?k--:0,j=sa[rk[i]-1];s[i+k]==s[j+k];k++);
} /// end-hash

template<class T>
inline void init(T s,const int len,const int sigma) { /// start-hash
    sais(s,sa,len,t,rk,ht,sigma);
} /// end-hash

template<class T>
inline void solve(T s,int len) {
    init(s,len+1,128);
    // getHeight(s,len);
}
} // namespace SuffixArray

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }

    void build(const vector<T> &values) {
        n = int(values.size());
        int levels = largest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        if (n > 0)
            range_min[0] = values;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query_value(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};

template<typename T, bool maximum_mode = false>
struct block_RMQ {
    static const int BLOCK = 8;
    const T DEFAULT_VALUE = maximum_mode ? numeric_limits<T>::lowest() : numeric_limits<T>::max();

    int n = 0;
    vector<T> values;
    vector<T> block_prefix, block_suffix;
    RMQ<T, maximum_mode> rmq;

    block_RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        block_prefix.assign(n + 1, DEFAULT_VALUE);
        block_suffix.assign(n + 1, DEFAULT_VALUE);

        for (int i = 1; i <= n; i++)
            if (i % BLOCK != 0)
                block_prefix[i] = better(block_prefix[i - 1], values[i - 1]);

        for (int i = n - 1; i >= 0; i--)
            if (i % BLOCK != 0)
                block_suffix[i] = better(block_suffix[i + 1], values[i]);

        vector<T> block_values(n / BLOCK);

        for (int i = 0; i < n / BLOCK; i++) {
            block_values[i] = values[BLOCK * i];

            for (int j = BLOCK * i + 1; j < BLOCK * (i + 1); j++)
                block_values[i] = better(block_values[i], values[j]);
        }

        rmq.build(block_values);
    }

    T query_value(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        T answer = DEFAULT_VALUE;

        // Check if we are strictly inside a block. Note we can't use (a - 1) / BLOCK because -1 / BLOCK rounds to 0.
        if ((a + BLOCK - 1) / BLOCK == b / BLOCK + 1) {
            for (int i = a; i < b; i++)
                answer = better(answer, values[i]);

            return answer;
        }

        answer = better(block_suffix[a], block_prefix[b]);
        a = (a + BLOCK - 1) / BLOCK;
        b /= BLOCK;

        if (a < b)
            answer = better(answer, rmq.query_value(a, b));

        return answer;
    }
};

template<typename T_string = string>
struct suffix_array {
    int n = 0;
    T_string str;
    vector<int> suffix;
    vector<int> rank;
    vector<int> lcp;
    block_RMQ<int> rmq;

    suffix_array() {}

    suffix_array(const T_string &_str, bool build_rmq = true) {
        build(_str, build_rmq);
    }

    void build(const T_string &_str, bool build_rmq = true) {
        str = _str;
        n = int(str.size());
        SuffixArray::solve(str, n);
        suffix.resize(n);

        for (int i = 0; i < n; i++)
            suffix[i] = SuffixArray::sa[i + 1];

        rank.resize(n);

        for (int i = 0; i < n; i++)
            rank[suffix[i]] = i;

        compute_lcp();

        if (build_rmq)
            rmq.build(lcp);
    }

    void compute_lcp() {
        lcp.assign(n, 0);
        int match = 0;

        for (int i = 0; i < n; i++) {
            if (rank[i] == 0)
                continue;

            int a = suffix[rank[i]] + match;
            int b = suffix[rank[i] - 1] + match;

            while (a < n && b < n && str[a++] == str[b++])
                match++;

            // lcp[r] = the longest common prefix length of the suffixes starting at suffix[r] and at suffix[r - 1].
            // Note that lcp[0] is always 0.
            lcp[rank[i]] = match;
            match = max(match - 1, 0);
        }
    }

    int get_lcp_from_ranks(int a, int b) const {
        if (a == b)
            return n - suffix[a];

        if (a > b)
            swap(a, b);

        return rmq.query_value(a + 1, b + 1);
    }

    int get_lcp(int a, int b) const {
        if (a >= n || b >= n)
            return 0;

        if (a == b)
            return n - a;

        return get_lcp_from_ranks(rank[a], rank[b]);
    }

    // Compares the substrings starting at `a` and `b` up to `length` in O(1).
    int compare(int a, int b, int length = -1) const {
        if (length < 0)
            length = n;

        if (a == b)
            return 0;

        int common = get_lcp(a, b);

        if (common >= length)
            return 0;

        if (a + common >= n || b + common >= n)
            return a + common >= n ? -1 : 1;

        return str[a + common] < str[b + common] ? -1 : (str[a + common] == str[b + common] ? 0 : 1);
    }
};


// Special chars that are smaller than a-z.
const char SPECIAL1 = '#';
const char SPECIAL2 = '$';

vector<mod_int> solve(string word, string next_word, vector<mod_int> dp) {
    assert(SPECIAL1 < SPECIAL2);
    word += SPECIAL1;
    next_word += SPECIAL2;
    int n = int(word.size());
    int m = int(next_word.size());
    next_word += SPECIAL2;
    assert(int(dp.size()) == n);


    vector<mod_int> dp_prefix_sum(n + 1, 0);

    for (int i = 0; i < n; i++)
        dp_prefix_sum[i + 1] = dp_prefix_sum[i] + dp[i];

    auto &&get_dp_sum = [&](int start, int end) {
        assert(0 <= start && start <= end && end <= n);
        return dp_prefix_sum[end] - dp_prefix_sum[start];
    };


    vector<mod_int> next_dp_change(m + 1, 0);

    auto &&increment_next_dp = [&](int start, int end, mod_int amount) {
        assert(0 <= start && start <= end && end <= m);
        next_dp_change[start] += amount;
        next_dp_change[end] -= amount;
    };


    suffix_array<string> SA(word + next_word);

    auto &&get_lcp = [&](int a, int b) {
        assert(0 <= a && a <= n);
        assert(0 <= b && b <= m);
        return min({SA.get_lcp(a, n + b), n - a, m - b});
    };

    auto &&less_equal = [&](int a, int b) {
        assert(0 <= a && a <= n);
        assert(0 <= b && b <= m);
        return a == n || SA.compare(a, n + b) <= 0;
    };


    vector<mod_int> less_equal_dp(min(n, m));

    for (int i = 0; i < min(n, m); i++)
        if (less_equal(i + 1, i + 1))
            less_equal_dp[i] = dp[i];

    vector<mod_int> less_equal_prefix_sum(min(n, m) + 1, 0);

    for (int i = 0; i < min(n, m); i++)
        less_equal_prefix_sum[i + 1] = less_equal_prefix_sum[i] + less_equal_dp[i];

    auto &&get_less_equal_sum = [&](int start, int end) {
        assert(0 <= start && start <= end && end <= min(n, m));
        return less_equal_prefix_sum[end] - less_equal_prefix_sum[start];
    };


    vector<mod_int> less_equal_change(m + 1, 0);

    auto &&increment_less_equal = [&](int start, int end, mod_int amount) {
        assert(0 <= start && start <= end && end <= min(n, m));
        less_equal_change[start] += amount;
        less_equal_change[end] -= amount;
    };


    vector<mod_int> next_dp(m, 0);
    int status = 0;

    for (int i = 0; i < min(n, m); i++) {
        if (status > 0)
            break;

        if (status < 0) {
            next_dp[i] += get_dp_sum(i, n);
            increment_next_dp(i + 1, m, dp[i]);
            continue;
        }

        assert(status == 0);

        if (less_equal(i + 1, i + 1))
            next_dp[i] += dp[i];

        // prev > next
        int lcp = get_lcp(i, i + 1);
        next_dp[i] += get_less_equal_sum(i + 1, i + lcp + 1);

        if (less_equal(i, i + 1))
            next_dp[i] += get_dp_sum(i + lcp + 1, n);

        // prev < next
        lcp = get_lcp(i + 1, i);
        increment_less_equal(i + 1, i + lcp + 1, dp[i]);

        if (less_equal(i + 1, i))
            increment_next_dp(i + lcp + 1, m, dp[i]);

        status = word[i] - next_word[i];
    }

    mod_int change = 0, le_change = 0;

    for (int i = 0; i < m; i++) {
        change += next_dp_change[i];
        le_change += less_equal_change[i];
        next_dp[i] += change;

        if (i >= n || less_equal(i + 1, i + 1))
            next_dp[i] += le_change;
    }

    return next_dp;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    string word;
    cin >> N >> word;
    vector<mod_int> dp(word.size() + 1, 1);

    for (int i = 1; i < N; i++) {
        string next_word;
        cin >> next_word;
        dp = solve(word, next_word, dp);
        word = next_word;
        dbg(word, dp);
    }

    cout << accumulate(dp.begin(), dp.end(), mod_int(0)) << '\n';
}