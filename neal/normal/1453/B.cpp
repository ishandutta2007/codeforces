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
    int N;
    cin >> N;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int64_t> dp_prefix(N + 1, 0);
    vector<int64_t> dp_suffix(N + 1, 0);

    for (int i = 1; i < N; i++)
        dp_prefix[i + 1] = dp_prefix[i] + abs(A[i - 1] - A[i]);

    for (int i = N - 2; i >= 0; i--)
        dp_suffix[i] = dp_suffix[i + 1] + abs(A[i] - A[i + 1]);

    int64_t best = INT64_MAX;

    for (int skip = 0; skip < N; skip++)
        best = min(best, dp_prefix[skip] + dp_suffix[skip + 1] + (0 < skip && skip < N - 1 ? abs(A[skip - 1] - A[skip + 1]) : 0));

    cout << best << '\n';
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