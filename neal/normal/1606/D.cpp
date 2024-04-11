
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
    vector<vector<int>> A(N, vector<int>(M));
    vector<vector<pair<int, int>>> columns(M, vector<pair<int, int>>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            columns[j][i] = {A[i][j], i};
        }

    for (int j = 0; j < M; j++)
        sort(columns[j].begin(), columns[j].end());

    vector<bool> is_red(N, false);
    vector<int> min_red(M, INF), max_red(M, -INF);
    vector<int> min_blue_index(M, 0), max_blue_index(M, N - 1);

    auto get_min = [&](int col) -> int {
        return columns[col][min_blue_index[col]].second;
    };

    auto get_max = [&](int col) -> int {
        return columns[col][max_blue_index[col]].second;
    };

    auto add_red = [&](int row) -> void {
        is_red[row] = true;

        for (int j = 0; j < M; j++) {
            min_red[j] = min(min_red[j], A[row][j]);
            max_red[j] = max(max_red[j], A[row][j]);

            while (is_red[get_min(j)])
                min_blue_index[j]++;

            while (is_red[get_max(j)])
                max_blue_index[j]--;

            assert(min_blue_index[j] <= max_blue_index[j]);
        }
    };

    auto evaluate = [&]() -> int {
        int left = 0, right = M;
        int minimum = INF, maximum = -INF;

        while (left < M && min(minimum, min_red[left]) > max(maximum, A[get_max(left)][left])) {
            minimum = min(minimum, min_red[left]);
            maximum = max(maximum, A[get_max(left)][left]);
            left++;
        }

        minimum = INF; maximum = -INF;

        while (right > 0 && max(maximum, max_red[right - 1]) < min(minimum, A[get_min(right - 1)][right - 1])) {
            maximum = max(maximum, max_red[right - 1]);
            minimum = min(minimum, A[get_min(right - 1)][right - 1]);
            right--;
        }

        assert(left <= right);

        if (left > 0 && right < M && left >= right)
            return min(left, M - 1);

        return -1;
    };

    for (int index = N - 1; index > 0; index--) {
        int row = columns[0][index].second;
        add_red(row);
        int split = evaluate();

        if (split >= 0) {
            string which(N, '?');

            for (int i = 0; i < N; i++)
                which[i] = is_red[i] ? 'R' : 'B';

            assert(which.find('R') != string::npos && which.find('B') != string::npos);
            assert(0 < split && split < M);

            cout << "YES" << '\n';
            cout << which << ' ' << split << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
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