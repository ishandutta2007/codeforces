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


void run_case() {
    auto solve = [&](vector<int64_t> X, int K) -> int64_t {
        assert(is_sorted(X.begin(), X.end()));
        int64_t total = 0;

        while (!X.empty()) {
            total += 2 * X.back();

            for (int i = 0; i < K && !X.empty(); i++)
                X.pop_back();
        }

        return total;
    };

    int N, K;
    cin >> N >> K;
    vector<int64_t> X(N);

    for (auto &x : X)
        cin >> x;

    sort(X.begin(), X.end());
    int64_t extreme = max(abs(X.front()), abs(X.back()));
    array<vector<int64_t>, 2> signs;

    for (auto &x : X)
        if (x < 0)
            signs[0].push_back(-x);
        else if (x > 0)
            signs[1].push_back(x);

    reverse(signs[0].begin(), signs[0].end());
    int64_t total = solve(signs[0], K) + solve(signs[1], K) - extreme;
    cout << total << '\n';
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