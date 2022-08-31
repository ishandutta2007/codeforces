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

#include <ext/pb_ds/priority_queue.hpp>

template<typename T>
using pbds_pq = __gnu_pbds::priority_queue<T>;

template<typename T>
using pbds_min_pq = __gnu_pbds::priority_queue<T, greater<T>>;

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

// Prime factorizes n in worst case O(sqrt n).
template<typename T>
vector<pair<T, int>> prime_factorize(T n) {
    assert(n >= 1);
    vector<pair<T, int>> result;

    auto extract = [&](T p) {
        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    };

    for (T p = 2; int64_t(p) * p <= n; p += p % 2 + 1)
        extract(p);

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}


void run_case() {
    int N, Q;
    cin >> N >> Q;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    vector<pair<int, int>> prime_factors = prime_factorize(N);
    vector<int> primes;

    for (auto &pf : prime_factors)
        primes.push_back(pf.first);

    int P = int(primes.size());
    vector<pbds_pq<int64_t>> prime_heap(P);
    vector<vector<pbds_pq<int64_t>::point_iterator>> heap_its(P);

    for (int i = 0; i < P; i++) {
        int p = primes[i];
        int Np = N / p;
        heap_its[i].assign(Np, prime_heap[i].end());

        for (int offset = 0; offset < Np; offset++) {
            int64_t sum = 0;

            for (int x = offset; x < N; x += Np)
                sum += A[x];

            heap_its[i][offset] = prime_heap[i].push(sum * Np);
        }
    }

    auto query = [&]() -> int64_t {
        int64_t maximum = 0;

        for (int i = 0; i < P; i++)
            maximum = max(maximum, prime_heap[i].top());

        return maximum;
    };

    auto update = [&](int index, int64_t x) -> void {
        for (int i = 0; i < P; i++) {
            int p = primes[i];
            int Np = N / p;
            int offset = index % Np;
            int64_t sum = *heap_its[i][offset];
            sum += int64_t(x - A[index]) * Np;
            prime_heap[i].modify(heap_its[i][offset], sum);
        }

        A[index] = x;
    };

    cout << query() << '\n';

    for (int q = 0; q < Q; q++) {
        int index;
        int64_t x;
        cin >> index >> x;
        index--;
        update(index, x);
        cout << query() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}