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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int> start(N + 1, -1), end(N + 1, -1), count(N + 1, 0);

    for (int i = 0; i < N; i++) {
        if (start[A[i]] < 0)
            start[A[i]] = i;

        end[A[i]] = i + 1;
        count[A[i]]++;
    }

    vector<int> suffix(N + 1, 0);
    vector<int> freq(N + 1, 0);
    int most = 0;

    for (int i = N - 1; i >= 0; i--) {
        most = max(most, ++freq[A[i]]);
        suffix[i] = most;
    }

    vector<int> dp(N + 1, 0);

    for (int i = 0; i < N; i++) {
        dp[i + 1] = dp[i];

        if (i == end[A[i]] - 1)
            dp[i + 1] = max(dp[i + 1], count[A[i]] + dp[start[A[i]]]);
    }

    most = 0;

    for (int x = 0; x <= N; x++)
        most = max(most, dp[x] + suffix[x]);

    cout << N - most << '\n';
}