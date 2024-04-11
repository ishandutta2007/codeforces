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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case() {
    auto available_squares = [](int n) -> int {
        return n * n - (n / 2) * (n / 2);
    };

    auto free_squares = [](int n) -> int {
        return ((n + 1) / 2) * ((n + 1) / 2);
    };

    auto paired_squares = [&](int n) -> int {
        return available_squares(n) - free_squares(n);
    };

    int M, K;
    cin >> M >> K;
    vector<int> A(K + 1, 0);

    for (int i = 1; i <= K; i++)
        cin >> A[i];

    int big = *max_element(A.begin(), A.end());
    int N = 1;

    while (available_squares(N) < M)
        N++;

    while (free_squares(N) + paired_squares(N) / 2 < big)
        N++;

    dbg(N);
    vector<vector<int>> solution(N, vector<int>(N, 0));
    int F = free_squares(N);
    int P = paired_squares(N);
    vector<pair<int, int>> A_sorted(K + 1);

    for (int i = 0; i <= K; i++)
        A_sorted[i] = {A[i], i};

    sort(A_sorted.rbegin(), A_sorted.rend());
    vector<int> half_values;

    for (int i = 0; i <= K; i++)
        for (int iter = 0; iter < A_sorted[i].first; iter++)
            half_values.push_back(A_sorted[i].second);

    if (int(half_values.size()) > P / 2)
        half_values.resize(P / 2);

    vector<int> free_values;

    for (int x : half_values)
        A[x]--;

    for (int x : half_values)
        while (A[x] > 0) {
            free_values.push_back(x);
            A[x]--;
        }

    vector<int> other_half;

    for (int i = 1; i <= K; i++)
        while (A[i] > 0 && int(other_half.size()) < P / 2) {
            other_half.push_back(i);
            A[i]--;
        }

    for (int i = 1; i <= K; i++)
        while (A[i] > 0) {
            free_values.push_back(i);
            A[i]--;
        }

    dbg(free_values);
    dbg(half_values);
    dbg(other_half);

    while (int(free_values.size()) < F)
        free_values.push_back(0);

    while (int(half_values.size()) < P / 2)
        half_values.push_back(0);

    while (int(other_half.size()) < P / 2)
        other_half.push_back(0);

    int fv = 0, hv = 0, oh = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    solution[i][j] = free_values[fv++];
                } else {
                    solution[i][j] = half_values[hv++];
                }
            } else {
                if (j % 2 == 0) {
                    solution[i][j] = other_half[oh++];
                } else {
                    solution[i][j] = 0;
                }
            }

    cout << N << '\n';

    for (auto &row : solution)
        output_vector(row);
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