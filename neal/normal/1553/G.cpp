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

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}


const int A_MAX = int(1e6) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    sieve(A_MAX);
    union_find UF(A_MAX);

    auto generate_primes = [&](int a) -> vector<int> {
        vector<int> a_primes;

        while (a > 1) {
            int p = smallest_factor[a];
            a_primes.push_back(p);

            do {
                a /= p;
            } while (a % p == 0);
        }

        return a_primes;
    };

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    for (int a : A) {
        int smallest = smallest_factor[a];

        for (int p : generate_primes(a))
            UF.unite(smallest, p);
    }

    auto generate_pair = [&](int x, int y) -> array<int, 2> {
        int x_root = UF.find(x);
        int y_root = UF.find(y);
        return {min(x_root, y_root), max(x_root, y_root)};
    };

    vector<array<int, 2>> one_move;

    for (int a : A) {
        vector<int> a_primes = generate_primes(a);
        vector<int> a1_primes = generate_primes(a + 1);

        for (int x : a_primes)
            for (int y : a1_primes)
                one_move.push_back(generate_pair(x, y));

        for (int x : a1_primes)
            for (int y : a1_primes)
                if (x < y)
                    one_move.push_back(generate_pair(x, y));
    }

    sort(one_move.begin(), one_move.end());
    one_move.erase(unique(one_move.begin(), one_move.end()), one_move.end());

    for (int q = 0; q < Q; q++) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        int a = A[s], b = A[t];
        vector<int> a_primes = generate_primes(a);
        vector<int> b_primes = generate_primes(b);
        int distance = 2;

        for (int x : a_primes)
            for (int y : b_primes)
                if (UF.find(x) == UF.find(y))
                    distance = 0;
                else if (distance > 1 && binary_search(one_move.begin(), one_move.end(), generate_pair(x, y)))
                    distance = 1;

        cout << distance << '\n';
    }
}