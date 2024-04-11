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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    int64_t K;
    cin >> N >> K;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    int zeros = int(count(A.begin(), A.end(), 0));
    int64_t sum = accumulate(A.begin(), A.end(), 0LL);

    if (abs(sum) > zeros * K) {
        cout << -1 << '\n';
        return 0;
    }

    auto solve = [&]() -> int64_t {
        int64_t current_sum = 0, full_sum = sum, max_sum = 0;
        int remaining = zeros;

        for (int i = 0; i < N; i++) {
            current_sum += A[i];
            max_sum = max(max_sum, current_sum);

            if (A[i] == 0) {
                remaining--;
                int64_t now = max(-K, min(K, remaining * K - full_sum));
                current_sum += now;
                full_sum += now;
                max_sum = max(max_sum, current_sum);
            }
        }

        return max_sum + 1;
    };

    int64_t best = 0;

    for (int iter = 0; iter < N; iter++) {
        rotate(A.begin(), A.begin() + 1, A.end());
        best = max(best, solve());
    }

    cout << best << '\n';
}