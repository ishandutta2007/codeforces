#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<const unsigned &MOD>
struct _m_uint {
    unsigned val;

    _m_uint(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    static unsigned inv_mod(unsigned a, unsigned m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        unsigned g = m, r = a, x = 0, y = 1;
        int sign = -1;

        while (r != 0) {
            unsigned q = g / r;
            g %= r; swap(g, r);
            x += q * y; swap(x, y);
            sign = -sign;
        }

        return sign > 0 ? x : m - x;
    }

    explicit operator unsigned() const { return val; }
    explicit operator uint64_t() const { return val; }

    _m_uint& operator+=(const _m_uint &other) {
        val = val < MOD - other.val ? val + other.val : val - (MOD - other.val);
        return *this;
    }

    _m_uint& operator-=(const _m_uint &other) {
        val = val < other.val ? val + (MOD - other.val) : val - other.val;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    _m_uint& operator*=(const _m_uint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    _m_uint& operator/=(const _m_uint &other) {
        return *this *= other.inv();
    }

    friend _m_uint operator+(const _m_uint &a, const _m_uint &b) { return _m_uint(a) += b; }
    friend _m_uint operator-(const _m_uint &a, const _m_uint &b) { return _m_uint(a) -= b; }
    friend _m_uint operator*(const _m_uint &a, const _m_uint &b) { return _m_uint(a) *= b; }
    friend _m_uint operator/(const _m_uint &a, const _m_uint &b) { return _m_uint(a) /= b; }

    _m_uint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_uint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_uint operator++(int) { _m_uint before = *this; ++*this; return before; }
    _m_uint operator--(int) { _m_uint before = *this; --*this; return before; }

    _m_uint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const _m_uint &other) const { return val == other.val; }
    bool operator!=(const _m_uint &other) const { return val != other.val; }

    _m_uint inv() const {
        return inv_mod(val);
    }

    _m_uint pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_uint a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _m_uint &m) {
        return os << m.val;
    }
};

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

// When P = 2^32 - 13337, both P and (P - 1) / 2 are prime.
extern const unsigned HASH_P = (unsigned) -13337;
using hash_int = _m_uint<HASH_P>;

const uint64_t HASH_P2 = (uint64_t) HASH_P * HASH_P;
const int HASH_COUNT = 1;

// Avoid multiplication bases near 0 or P - 1.
uniform_int_distribution<unsigned> MULT_DIST(0.1 * HASH_P, 0.9 * HASH_P);
const hash_int HASH_MULT[] = {MULT_DIST(rng), MULT_DIST(rng)};
const hash_int HASH_INV[] = {1 / HASH_MULT[0], 1 / HASH_MULT[1]};

vector<hash_int> hash_pow[] = {{1}, {1}};

const int INF = 1e9 + 5;

template<typename T_string = string>
struct string_hash {
    static const bool BUILD_REVERSE = false;

    T_string str;
    vector<hash_int> _prefix[HASH_COUNT];
    vector<hash_int> _inv_prefix[HASH_COUNT];

    string_hash() {
        build({});
    }

    string_hash(const T_string &_str) {
        build(_str);
    }

    int length() const {
        return (int) _prefix[0].size() - 1;
    }

    template<typename T_char>
    void add_char(const T_char &c) {
        str.push_back(c);

        for (int h = 0; h < HASH_COUNT; h++) {
            _prefix[h].push_back(HASH_MULT[h] * _prefix[h].back() + c);

            if (hash_pow[h].size() < _prefix[h].size())
                hash_pow[h].push_back(HASH_MULT[h] * hash_pow[h].back());

            if (BUILD_REVERSE)
                _inv_prefix[h].push_back((_inv_prefix[h].back() + c) * HASH_INV[h]);
        }
    }

    void pop_char() {
        str.pop_back();

        for (int h = 0; h < HASH_COUNT; h++) {
            _prefix[h].pop_back();

            if (BUILD_REVERSE)
                _inv_prefix[h].pop_back();
        }
    }

    void build(const T_string &_str) {
        str = {};
        str.reserve(_str.size());

        for (int h = 0; h < HASH_COUNT; h++) {
            _prefix[h] = {0};
            _prefix[h].reserve(_str.size() + 1);

            if (BUILD_REVERSE) {
                _inv_prefix[h] = {0};
                _inv_prefix[h].reserve(_str.size() + 1);
            }
        }

        for (auto &c : _str)
            add_char(c);
    }

    uint64_t _single_hash(int h, int start, int end) const {
        // Convert everything to `uint64_t` to optimize speed.
        uint64_t power = (uint64_t) hash_pow[h][end - start];
        return (power + (uint64_t) _prefix[h][end] + HASH_P2 - (uint64_t) _prefix[h][start] * power) % HASH_P;
    }

    uint64_t substring_hash(int start, int end) const {
        assert(0 <= start && start <= end && end <= length());
        return _single_hash(0, start, end) + (HASH_COUNT > 1 ? _single_hash(1, start, end) << 32 : 0);
    }

    uint64_t _reverse_single_hash(int h, int start, int end) const {
        // Convert everything to `uint64_t` to optimize speed.
        uint64_t power = (uint64_t) hash_pow[h][end - start];
        return (power + (uint64_t) _inv_prefix[h][end] * power + HASH_P - (uint64_t) _inv_prefix[h][start]) % HASH_P;
    }

    uint64_t reverse_substring_hash(int start, int end) const {
        assert(0 <= start && start <= end && end <= length());
        return _reverse_single_hash(0, start, end) + (HASH_COUNT > 1 ? _reverse_single_hash(1, start, end) << 32 : 0);
    }

    bool equal(int start1, int start2, int length) const {
        return substring_hash(start1, start1 + length) == substring_hash(start2, start2 + length);
    }

    bool is_palindrome(int start, int end) const {
        return substring_hash(start, end) == reverse_substring_hash(start, end);
    }

    int compare(int start1, int start2, int max_length = INF) const;
};

template<typename T_string>
int first_mismatch(const string_hash<T_string> &hash1, int start1,
                   const string_hash<T_string> &hash2, int start2, int max_length = INF) {
    max_length = min({max_length, hash1.length() - start1, hash2.length() - start2});

    static const int FIRST = 5;
    int first = min(max_length, FIRST);

    for (int i = 0; i < first; i++)
        if (hash1.str[start1 + i] != hash2.str[start2 + i])
            return i;

    if (hash1.substring_hash(start1, start1 + max_length) == hash2.substring_hash(start2, start2 + max_length))
        return max_length;

    static const int MANUAL = 15;
    int low = first, high = max_length - 1;

    while (high - low > MANUAL) {
        int mid = (low + high + 1) / 2;

        if (hash1.substring_hash(start1, start1 + mid) == hash2.substring_hash(start2, start2 + mid))
            low = mid;
        else
            high = mid - 1;
    }

    for (int i = low; i < high; i++)
        if (hash1.str[start1 + i] != hash2.str[start2 + i])
            return i;

    return high;
}

template<typename T_string>
int hash_compare(const string_hash<T_string> &hash1, int start1,
                 const string_hash<T_string> &hash2, int start2, int max_length = INF) {
    int mismatch = first_mismatch(hash1, start1, hash2, start2, max_length);
    int length1 = min(hash1.length() - start1, max_length);
    int length2 = min(hash2.length() - start2, max_length);

    if (mismatch == min(length1, length2))
        return length1 == length2 ? 0 : (length1 < length2 ? -1 : +1);

    if (hash1.str[start1 + mismatch] == hash2.str[start2 + mismatch])
        return 0;

    return hash1.str[start1 + mismatch] < hash2.str[start2 + mismatch] ? -1 : +1;
}

template<typename T_string>
int string_hash<T_string>::compare(int start1, int start2, int max_length) const {
    return hash_compare(*this, start1, *this, start2, max_length);
}



using seq_hash = string_hash<vector<int>>;

int N, bucket_size, n_buckets;
vector<int> S;
vector<bool> invalid_bucket;
vector<seq_hash> bucket_prefix, bucket_suffix;

int which_bucket(int index) {
    return index < N ? index / bucket_size : n_buckets;
}

int get_bucket_start(int b) {
    return min(bucket_size * b, N);
}

int get_bucket_end(int b) {
    return min(bucket_size * (b + 1), N);
}

vector<int> process_stack(int start, int end) {
    assert(start <= end);
    vector<int> stack;
    stack.reserve(end - start);

    for (int i = start; i < end; i++)
        if (!stack.empty() && stack.back() > 0 && S[i] == -stack.back())
            stack.pop_back();
        else
            stack.push_back(S[i]);

    return stack;
}

void build_bucket(int b) {
    assert(0 <= b && b < n_buckets);
    int bucket_start = get_bucket_start(b);
    int bucket_end = get_bucket_end(b);

    vector<int> stack = process_stack(bucket_start, bucket_end);
    int size = stack.size();
    int prefix = 0, suffix = size;

    while (prefix < size && stack[prefix] < 0)
        prefix++;

    while (suffix > 0 && stack[suffix - 1] > 0)
        suffix--;

    if (prefix != suffix) {
        invalid_bucket[b] = true;
        return;
    }

    invalid_bucket[b] = false;
    bucket_prefix[b] = {};

    for (int i = prefix - 1; i >= 0; i--)
        bucket_prefix[b].add_char(abs(stack[i]));

    bucket_suffix[b] = {};

    for (int i = suffix; i < size; i++)
        bucket_suffix[b].add_char(stack[i]);
}

void init_buckets() {
    bucket_size = 1.5 * sqrt(N) + 1;
    n_buckets = (N + bucket_size - 1) / bucket_size;
    invalid_bucket.assign(n_buckets, false);
    bucket_prefix.assign(n_buckets, {});
    bucket_suffix.assign(n_buckets, {});

    for (int b = 0; b < n_buckets; b++)
        build_bucket(b);
}

void update(int index, int change) {
    assert(0 <= index && index < N);
    S[index] = change;
    build_bucket(which_bucket(index));
}

struct range {
    const seq_hash *hasher = nullptr;
    int start = 0, end = 0;

    range() {}

    range(const seq_hash &_hasher, int _start, int _end) : hasher(&_hasher), start(_start), end(_end) {}

    int length() const {
        return end - start;
    }
};

bool query(int start, int end) {
    assert(0 <= start && start <= end && end <= N);
    int start_b = which_bucket(start), end_b = which_bucket(end);

    if (start_b == end_b)
        return process_stack(start, end).empty();

    vector<range> ranges;
    ranges.reserve(n_buckets + 1);
    vector<int> stack = process_stack(start, get_bucket_end(start_b));
    dbg("start", stack);

    for (int x : stack)
        if (x < 0)
            return false;

    seq_hash start_hasher(stack);
    ranges.emplace_back(start_hasher, 0, start_hasher.length());

    for (int b = start_b + 1; b < end_b; b++) {
        if (invalid_bucket[b])
            return false;

        dbg(b, bucket_prefix[b].str, bucket_suffix[b].str);
        int prefix_end = bucket_prefix[b].length();

        while (prefix_end > 0) {
            if (ranges.empty())
                return false;

            range &back = ranges.back();

            int take = min(prefix_end, back.length());
            uint64_t prefix_hash = bucket_prefix[b].substring_hash(prefix_end - take, prefix_end);
            uint64_t range_hash = back.hasher->substring_hash(back.end - take, back.end);

            if (prefix_hash != range_hash)
                return false;

            prefix_end -= take;
            back.end -= take;

            if (back.length() == 0)
                ranges.pop_back();
        }

        assert(prefix_end == 0);
        ranges.emplace_back(bucket_suffix[b], 0, bucket_suffix[b].length());
    }

    stack = process_stack(get_bucket_start(end_b), end);
    dbg("end", stack);

    for (int x : stack)
        if (x > 0)
            return false;

    for (int x : stack) {
        while (!ranges.empty() && ranges.back().length() == 0)
            ranges.pop_back();

        if (ranges.empty())
            return false;

        range &back = ranges.back();

        if (back.hasher->str[back.end - 1] != abs(x))
            return false;

        back.end--;
    }

    while (!ranges.empty() && ranges.back().length() == 0)
        ranges.pop_back();

    return ranges.empty();
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int _;
    cin >> N >> _;
    S.resize(N);

    for (auto &s : S)
        cin >> s;

    init_buckets();
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            int index, t;
            cin >> index >> t;
            index--;
            update(index, t);
        } else if (type == 2) {
            int L, R;
            cin >> L >> R;
            L--;
            cout << (query(L, R) ? "Yes" : "No") << '\n';
        } else {
            assert(false);
        }
    }
}