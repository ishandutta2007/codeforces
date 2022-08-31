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
    vector<int> A(N);
    int64_t sum = 0;

    for (auto &a : A) {
        cin >> a;
        sum += a;
    }

    vector<int> counts(N + 1, 0);
    int64_t prefix = 0;

    for (auto &a : A) {
        prefix += a;
        int64_t g = __gcd(prefix, sum);
        int64_t len = sum / g;

        if (len <= N)
            counts[len]++;
    }

    for (int x = N; x > 0; x--)
        for (int y = 2 * x; y <= N; y += x)
            counts[y] += counts[x];

    int answer = N;

    for (int len = N; len > 0; len--)
        if (counts[len] == len)
            answer = min(answer, N - len);

    cout << answer << '\n';
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