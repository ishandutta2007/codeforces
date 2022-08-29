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
    string S;
    cin >> S;
    int N = int(S.size());
    vector<int> prefix_count[2][2];

    for (int x = 0; x < 2; x++)
        for (int p = 0; p < 2; p++) {
            prefix_count[x][p].assign(N + 1, 0);

            for (int i = 0; i < N; i++)
                prefix_count[x][p][i + 1] = prefix_count[x][p][i] + (i % 2 == p && S[i] - '0' == x);
        }

    auto exists = [&](int start, int end, int x, int p) -> bool {
        return prefix_count[x][p][end] - prefix_count[x][p][start] > 0;
    };

    auto beautiful = [&](int start, int end) -> bool {
        for (int x = 0; x < 2; x++)
            if (exists(start, end, x, 0) && exists(start, end, x, 1))
                return false;

        for (int p = 0; p < 2; p++)
            if (exists(start, end, 0, p) && exists(start, end, 1, p))
                return false;

        return true;
    };

    int64_t total = 0;

    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && beautiful(i, j + 1))
            j++;

        total += j - i;
    }

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