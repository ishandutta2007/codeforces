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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int INF = int(1e9) + 5;

struct state {
    int high = -INF, low = -INF;
    int previous = -1, a = 0;

    bool operator<(const state &other) const {
        if (high != other.high)
            return high < other.high;

        return low < other.low;
    }

    pair<state, bool> add(int from, int x) {
        if (x < low)
            return {state(), false};

        state sum = *this;
        sum.previous = from;
        sum.a = x;

        if (x > high)
            sum.high = x;
        else
            sum.low = x;

        return {sum, true};
    }
};

void run_case() {
    int N;
    cin >> N;
    vector<int> P(N);

    for (auto &p : P)
        cin >> p;

    vector<vector<state>> dp(N + 1);
    dp[0] = {state()};

    for (int i = 0; i < N; i++) {
        for (int x : {-P[i], P[i]})
            for (int j = 0; j < int(dp[i].size()); j++) {
                state s = dp[i][j];
                pair<state, bool> result = s.add(j, x);

                if (result.second)
                    dp[i + 1].push_back(result.first);
            }

        sort(dp[i + 1].begin(), dp[i + 1].end());
        vector<state> filtered;

        for (state s : dp[i + 1]) {
            bool bad = false;

            for (state f : filtered)
                if (f.low <= s.low && f.high <= s.high)
                    bad = true;

            if (!bad)
                filtered.push_back(s);
        }

        dp[i + 1] = filtered;
    }

    if (dp.back().empty()) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    vector<int> A(N);
    int index = 0;

    for (int i = N - 1; i >= 0; i--) {
        state s = dp[i + 1][index];
        A[i] = s.a;
        index = s.previous;
    }

    output_vector(A);
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