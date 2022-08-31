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


const int INF = int(1e9) + 5;

void run_case() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);

    for (auto &row : grid)
        cin >> row;

    auto solve = [&](int dist) -> array<int, 2> {
        int x_low = -INF, x_high = INF;
        int y_low = -INF, y_high = INF;

        for (int r = 0; r < N; r++)
            for (int c = 0; c < M; c++)
                if (grid[r][c] == 'B') {
                    int x = r - c;
                    int y = r + c;
                    x_low = max(x_low, x - dist);
                    x_high = min(x_high, x + dist);
                    y_low = max(y_low, y - dist);
                    y_high = min(y_high, y + dist);
                }

        for (int x = x_low; x <= x_high; x++)
            for (int y = y_low; y <= y_high; y++)
                if ((x + y) % 2 == 0) {
                    int r = (x + y) / 2;
                    int c = (y - x) / 2;

                    if (0 <= r && r < N && 0 <= c && c < M)
                        return {r, c};
                }

        return {-1, -1};
    };

    int low = 0, high = (N - 1) + (M - 1);

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (solve(mid)[0] >= 0)
            high = mid;
        else
            low = mid + 1;
    }

    dbg(low);
    array<int, 2> answer = solve(low);
    cout << answer[0] + 1 << ' ' << answer[1] + 1 << '\n';
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