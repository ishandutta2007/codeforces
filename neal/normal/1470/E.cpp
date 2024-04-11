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
    int N, C, Q;
    cin >> N >> C >> Q;
    vector<int> P(N);

    for (auto &p : P)
        cin >> p;

    vector<vector<array<int64_t, 2>>> range(C + 1, vector<array<int64_t, 2>>(N + 1, {0, 1}));
    vector<vector<int64_t>> dp(C + 1, vector<int64_t>(N + 1, 0));

    for (int c = 0; c <= C; c++)
        dp[c][N] = 1;

    for (int start = N - 1; start >= 0; start--) {
        dp[0][start] = 1;

        for (int c = 1; c <= C; c++)
            for (int take = 1; take <= c + 1 && start + take <= N; take++)
                dp[c][start] += dp[c - (take - 1)][start + take];
    }

    for (int start = N - 1; start >= 0; start--)
        for (int c = 1; c <= C; c++) {
            int64_t range_start = 0, range_end = 0;

            for (int take = 1; take <= c + 1 && start + take <= N; take++) {
                int last = P[start + take - 1];

                if (last < P[start]) {
                    int64_t add = dp[c - (take - 1)][start + take];
                    range_start += add;
                    range_end += add;
                } else if (last == P[start]) {
                    int64_t add = dp[c - (take - 1)][start + take];
                    range_end += add;
                }
            }

            range[c][start] = {range_start, range_end};
        }

    vector<vector<int64_t>> range_start_sum(C + 1, vector<int64_t>(N + 2, 0));

    for (int c = 0; c <= C; c++)
        for (int i = 0; i <= N; i++)
            range_start_sum[c][i + 1] = range_start_sum[c][i] + range[c][i][0];

    for (int q = 0; q < Q; q++) {
        int64_t idx, j;
        cin >> idx >> j;
        idx--; j--;
        int c = C, answer = -1;

        if (j >= dp[C][0]) {
            cout << -1 << '\n';
            continue;
        }

        int start = 0;

        while (start < N) {
            if (range[c][start][0] <= j && j < range[c][start][1]) {
                if (idx == start) {
                    answer = P[idx];
                    goto finish;
                }

                int low = start, high = N;

                while (low < high) {
                    int mid = low + (high - low) / 2;

                    int64_t range_sum = range_start_sum[c][mid] - range_start_sum[c][start];
                    int64_t range_start = range_sum + range[c][mid][0];
                    int64_t range_end = range_sum + range[c][mid][1];

                    if (range_start <= j && j < range_end)
                        low = mid + 1;
                    else
                        high = mid;
                }

                if (start <= idx && idx < low) {
                    answer = P[idx];
                    goto finish;
                }

                j -= range_start_sum[c][low] - range_start_sum[c][start];
                start = low;
            } else {
                vector<pair<int, int>> choices;

                for (int i = start; i <= start + c && i < N; i++)
                    choices.emplace_back(P[i], i);

                sort(choices.begin(), choices.end());

                for (auto &pr : choices) {
                    int i = pr.second;
                    int take = i - start + 1;
                    int64_t add = dp[c - (take - 1)][start + take];

                    if (0 <= j && j < add) {
                        if (start <= idx && idx < start + take) {
                            answer = P[start + (start + take - 1 - idx)];
                            goto finish;
                        }

                        c -= take - 1;
                        start += take;
                        break;
                    }

                    j -= add;
                }
            }
        }

        finish:
        cout << answer << '\n';
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