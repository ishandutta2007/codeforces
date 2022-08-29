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
    int N, K;
    string S;
    cin >> N >> K >> S;

    auto down = [&](char ch) -> char {
        return ch == 'a' ? char('a' + K - 1) : char(ch - 1);
    };

    auto up = [&](char ch) -> char {
        return ch == char('a' + K - 1) ? 'a' : char(ch + 1);
    };

    string dp, dp_gap;

    for (int i = 0; i < N; i++) {
        // Transitions from dp[i]
        string next_dp = dp + min({S[i], down(S[i]), up(S[i])});
        string next_dp_gap = dp + S[i];

        if (i >= 1)
            next_dp = min(next_dp, dp.substr(0, i - 1) + S[i] + dp.back());

        // Transitions from dp_gap[i]
        if (i >= 1)
            next_dp = min(next_dp, dp_gap.substr(0, i - 1) + min({S[i], down(S[i]), up(S[i])}) + dp_gap.back());

        if (i >= 2)
            next_dp = min(next_dp, dp_gap.substr(0, i - 2) + S[i] + dp_gap.substr(i - 2));

        next_dp = min(next_dp, dp_gap + S[i]);
        swap(dp, next_dp);
        swap(dp_gap, next_dp_gap);
    }

    cout << dp << '\n';
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