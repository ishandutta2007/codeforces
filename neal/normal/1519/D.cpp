#include <algorithm>
#include <array>
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
    cin >> N;
    vector<int64_t> A(N), B(N);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    int64_t total = 0;

    for (int i = 0; i < N; i++)
        total += A[i] * B[i];

    int64_t best = total;

    for (int center = 0; center < N; center++) {
        int64_t current = total;

        for (int x = center - 1, y = center + 1; x >= 0 && y < N; x--, y++) {
            current -= A[x] * B[x] + A[y] * B[y];
            current += A[x] * B[y] + A[y] * B[x];
            best = max(best, current);
        }
    }

    for (int between = 0; between < N - 1; between++) {
        int64_t current = total;

        for (int x = between, y = between + 1; x >= 0 && y < N; x--, y++) {
            current -= A[x] * B[x] + A[y] * B[y];
            current += A[x] * B[y] + A[y] * B[x];
            best = max(best, current);
        }
    }

    cout << best << '\n';
}