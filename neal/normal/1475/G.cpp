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


const int A_MAX = 200005;
const int INF = int(1e9) + 5;

void run_case() {
    int N;
    cin >> N;
    vector<int> freq(A_MAX, 0);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        freq[a]++;
    }

    vector<int> freq_sum(A_MAX + 1, 0);

    for (int a = 0; a < A_MAX; a++)
        freq_sum[a + 1] = freq_sum[a] + freq[a];

    vector<int> dp(A_MAX, INF);

    for (int x = A_MAX - 1; x > 0; x--) {
        dp[x] = freq_sum.back() - freq_sum[x + 1];

        for (int y = 2 * x; y < A_MAX; y += x)
            dp[x] = min(dp[x], dp[y] + freq_sum[y] - freq_sum[x + 1]);
    }

    cout << dp[1] << '\n';
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