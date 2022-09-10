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


const int LOSE = 0, DRAW = 1, WIN = 2;

void run_case() {
    string S;
    cin >> S;
    int N = int(S.size());
    vector<vector<array<int, 3>>> dp(N + 1, vector<array<int, 3>>(N + 1, {-1, -1, -1}));

    auto evaluate = [&](char a, char b, int current) -> int {
        if (a == b)
            return current;

        return a < b ? WIN : LOSE;
    };

    auto solve = y_combinator([&](auto self, int start, int end, int current) -> int {
        int &ans = dp[start][end][current];

        if (start >= end)
            return current;

        if (ans >= 0)
            return ans;

        assert((end - start) % 2 == 0);

        // Take S[start]
        int start_result = min(
            self(start + 2, end, evaluate(S[start], S[start + 1], current)),
            self(start + 1, end - 1, evaluate(S[start], S[end - 1], current))
        );

        // Take S[end - 1]
        int end_result = min(
            self(start + 1, end - 1, evaluate(S[end - 1], S[start], current)),
            self(start, end - 2, evaluate(S[end - 1], S[end - 2], current))
        );

        return ans = max(start_result, end_result);
    });

    int ans;

    if (N % 2 == 0)
        ans = solve(0, N, DRAW);
    else
        ans = max(solve(0, N - 1, LOSE), solve(1, N, LOSE));

    if (ans == WIN)
        cout << "Alice" << '\n';
    else if (ans == DRAW)
        cout << "Draw" << '\n';
    else if (ans == LOSE)
        cout << "Bob" << '\n';
    else
        assert(false);
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