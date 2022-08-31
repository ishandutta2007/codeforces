#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int INF = 1e9 + 5;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<array<int, 2>> dp(N + 1, {INF, INF});
    dp[0][1] = 0;

    for (int i = 0; i < N; i++)
        for (int who = 0; who < 2; who++)
            for (int fight = 1; fight <= min(N - i, 2); fight++) {
                int hard = A[i] + (fight > 1 ? A[i + 1] : 0);
                dp[i + fight][!who] = min(dp[i + fight][!who], dp[i][who] + who * hard);
            }

    cout << min(dp[N][0], dp[N][1]) << '\n';
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