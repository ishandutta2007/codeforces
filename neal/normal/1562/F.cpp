#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct montgomery {
    montgomery(uint64_t n) : mod(n) {
        assert(n % 2 != 0 && n < 1LLU << 63);
        inv = n;
        for (int i = 0; i < 6; i++) inv *= 2 - n * inv;
        assert(n * inv == 1);
        // r2 = 2^128 mod n
        r2 = -n % n;
        r2 = uint64_t(__uint128_t(r2) * r2 % n);
    }
    static uint64_t hi(__uint128_t x) { return uint64_t(x >> 64); }
    static uint64_t lo(__uint128_t x) { return uint64_t(x); }
    uint64_t reduce(__uint128_t x) const {
        uint64_t y = hi(x) - hi(__uint128_t(lo(x) * inv) * mod);
        return int64_t(y) < 0 ? y + mod : y;
    }
    uint64_t reduce(uint64_t x) const { return reduce(__uint128_t(x)); }
    uint64_t init(uint64_t n) const { return reduce(__uint128_t(n) * r2); }
    uint64_t mul(uint64_t a, uint64_t b) const { return reduce(__uint128_t(a) * b); }
    uint64_t pow(uint64_t a, uint64_t b) const {
        uint64_t p = init(1);
        while (b > 0) {
            if (b & 1) p = mul(p, a);
            b >>= 1;
            if (b > 0) a = mul(a, a);
        }
        return p;
    }
    uint64_t mod, inv, r2;
};

bool miller_rabin(uint64_t n) {
    if (n < 2)
        return false;

    // Check small primes.
    for (uint64_t p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;

    // https://miller-rabin.appspot.com/
    auto get_miller_rabin_bases = [&]() -> vector<uint64_t> {
        if (n < 341531) return {9345883071009581737LLU};
        if (n < 1050535501) return {336781006125, 9639812373923155};
        if (n < 350269456337) return {4230279247111683200, 14694767155120705706LLU, 16641139526367750375LLU};
        if (n < 55245642489451) return {2, 141889084524735, 1199124725622454117, 11096072698276303650LLU};
        if (n < 7999252175582851) return {2, 4130806001517, 149795463772692060, 186635894390467037, 3967304179347715805};
        if (n < 585226005592931977) return {2, 123635709730000, 9233062284813009, 43835965440333360, 761179012939631437, 1263739024124850375};
        return {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    };

    int r = __builtin_ctzll(n - 1);
    uint64_t d = (n - 1) >> r;
    montgomery mont(n);
    uint64_t one = mont.init(1), neg_one = mont.init(n - 1);

    for (uint64_t a : get_miller_rabin_bases()) {
        if (a % n == 0)
            continue;

        uint64_t x = mont.pow(mont.init(a % n), d);

        if (x == one || x == neg_one)
            continue;

        for (int i = 0; i < r - 1 && x != neg_one; i++)
            x = mont.mul(x, x);

        if (x != neg_one)
            return false;
    }

    return true;
}

template<typename T>
T binary_gcd(T a, T b) {
    if (a == 0 || b == 0)
        return a + b;

    int common = __builtin_ctzll(a | b);
    b >>= __builtin_ctzll(b);

    do {
        a >>= __builtin_ctzll(a);

        if (a < b)
            swap(a, b);

        a -= b;
    } while (a != 0);

    return b << common;
}

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

uint64_t pollard_rho(uint64_t n) {
    // Check small primes.
    for (uint64_t p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return p;

    montgomery mont(n);

    uint64_t increment;
    auto g = [&](uint64_t x) -> uint64_t {
        // Note this is technically the wrong way to add, but it doesn't matter since increment is random anyway.
        return mont.reduce(__uint128_t(x) * x + increment);
    };

    // Choose a jump size much larger than log(n) but much smaller than n^(1/4).
    int jump = int(sqrt(log(n) * sqrt(sqrt(n))));

    while (true) {
        increment = rng() % n;
        uint64_t start = rng() % n;
        uint64_t x = start, y = start, p = 1;
        vector<uint64_t> products(jump + 1);

        // https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm#Variants
        do {
            products[0] = 1;

            for (int i = 1; i <= jump; i++) {
                x = g(x);
                y = g(g(y));
                products[i] = mont.mul(products[i - 1], max(x, y) - min(x, y));
            }
        } while ((p = binary_gcd(products[jump], n)) == 1);

        if (p == n) {
            assert(products[jump] == 0);
            int index = jump;

            while (index > 0 && products[index] == 0)
                index--;

            p = binary_gcd(products[index], n);
        }

        if (p != 1 && p != n)
            return p;
    }
}

template<typename T>
map<T, int> prime_factorize(T n) {
    assert(n <= INT64_MAX);

    if (n == 1)
        return {};

    if (miller_rabin(n))
        return {{n, 1}};

    T x = pollard_rho(n);
    map<T, int> A = prime_factorize(x), B = prime_factorize(n / x);

    if (A.size() < B.size())
        swap(A, B);

    for (pair<T, int> p : B)
        A[p.first] += p.second;

    return A;
}


const int EXTRA = 5000;
const int CUTOFF = 100;

void run_case() {
    int N;
    cin >> N;

    auto query = [&](int x, int y) -> int64_t {
        assert(0 <= x && x < N && 0 <= y && y < N);
        assert(x != y);
        cout << "? " << x + 1 << ' ' << y + 1 << endl;
        int64_t result;
        cin >> result;
        return result;
    };

    if (N <= CUTOFF) {
        vector<vector<int64_t>> lcms(N, vector<int64_t>(N, 0));

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                lcms[i][j] = lcms[j][i] = query(i, j);

        int64_t largest = 0;
        vector<int> order(N, -1);

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                if (lcms[i][j] > largest) {
                    largest = lcms[i][j];
                    order[0] = i;
                    order[1] = j;
                }

        int64_t R = int(ceil(sqrt(largest)));

        for (int i = 0; i < N; i++)
            if (i != order[0] && i != order[1]) {
                if (lcms[i][order[0]] == (R - 1) * (R - 2)) {
                    swap(order[0], order[1]);
                    order[2] = i;
                    break;
                }

                if (lcms[i][order[1]] == (R - 1) * (R - 2)) {
                    order[2] = i;
                    break;
                }
            }

        for (int x = 3; x < N; x++) {
            for (int i = 0; i < N; i++)
                if (find(order.begin(), order.end(), i) == order.end() && lcms[i][order[x - 1]] == (R - x + 1) * (R - x)) {
                    order[x] = i;
                    break;
                }
        }

        vector<int64_t> perm(N, -1);

        for (int i = 0; i < N; i++)
            perm[order[i]] = R - i;

        cout << '!';

        for (int64_t x : perm)
            cout << ' ' << x;

        cout << endl;
        return;
    }

    int64_t biggest = -1;
    array<int, 2> options = {-1, -1};

    for (int iter = 0; iter < EXTRA; iter++) {
        int x, y;

        do {
            x = int(rng() % N);
            y = int(rng() % N);
        } while (x == y);

        int64_t lcm = query(x, y);
        map<int64_t, int> prime_factors = prime_factorize(lcm);

        if (prime_factors.rbegin()->first > biggest) {
            biggest = prime_factors.rbegin()->first;
            options = {x, y};
        }
    }

    int other = 0;

    while (other == options[0] || other == options[1])
        other++;

    if (query(other, options[1]) % biggest == 0)
        swap(options[0], options[1]);

    vector<int64_t> perm(N);
    perm[options[0]] = biggest;

    for (int i = 0; i < N; i++)
        if (i != options[0])
            perm[i] = query(i, options[0]) / biggest;

    cout << '!';

    for (int64_t x : perm)
        cout << ' ' << x;

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}