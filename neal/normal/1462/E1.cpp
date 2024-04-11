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


int64_t solve(vector<int> freq, int N, int M, int K) {
    vector<int> prefix_sum(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sum[i + 1] = prefix_sum[i] + freq[i];

    assert(M == 3);
    int64_t total = 0;

    for (int a = -K; a < N; a++) {
        int64_t count = prefix_sum[min(a + K + 1, N)] - prefix_sum[max(a, 0)];
        total += count * (count - 1) * (count - 2) / 6;
    }

    return total;
}

void run_case() {
    int N;
    cin >> N;
    int M = 3, K = 2;
    vector<int> A(N);

    for (auto &a : A) {
        cin >> a;
        a--;
    }

    vector<int> freq(N, 0);

    for (auto &a : A)
        freq[a]++;

    dbg(solve(freq, N, M, K), solve(freq, N, M, K - 1));
    cout << solve(freq, N, M, K) - solve(freq, N, M, K - 1) << '\n';
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