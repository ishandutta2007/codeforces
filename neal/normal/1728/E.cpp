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

int64_t inv_mod(int64_t a, int64_t m) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int64_t g = m, r = a, x = 0, y = 1;

    while (r != 0) {
        int64_t q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }

    return x < 0 ? x + m : x;
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int64_t> A(N), B(N), D(N);
    int64_t A_sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        D[i] = B[i] - A[i];
        A_sum += A[i];
    }

    sort(D.begin(), D.end(), greater<int64_t>());
    vector<int64_t> D_prefix_sum(N + 1, 0);

    for (int i = 0; i < N; i++)
        D_prefix_sum[i + 1] = D_prefix_sum[i] + D[i];

    int64_t optimal = int(max_element(D_prefix_sum.begin(), D_prefix_sum.end()) - D_prefix_sum.begin());
    int M;
    cin >> M;

    for (int q = 0; q < M; q++) {
        int64_t x, y;
        cin >> x >> y;
        int64_t g = __gcd(x, y);

        if (N % g != 0) {
            cout << -1 << '\n';
            continue;
        }

        x /= g;
        y /= g;
        int64_t Ng = N / g;
        int64_t b = Ng * inv_mod(y, x) % x;
        int64_t minimum = b * y;

        if (minimum > Ng) {
            cout << -1 << '\n';
            continue;
        }

        if (optimal / g > minimum)
            minimum += (optimal / g - minimum) / (x * y) * (x * y);

        int64_t ans = A_sum + D_prefix_sum[g * minimum];

        if (minimum + x * y <= Ng) {
            minimum += x * y;
            ans = max(ans, A_sum + D_prefix_sum[g * minimum]);
        }

        // for (int64_t black = minimum; black <= Ng; black += x * y)
        //     ans = max(ans, A_sum + D_prefix_sum[g * black]);

        cout << ans << '\n';
    }
}