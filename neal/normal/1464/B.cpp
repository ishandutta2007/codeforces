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


const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    string S;
    int64_t X, Y;
    cin >> S >> X >> Y;
    int N = int(S.size());
    int64_t best = INF64;

    for (int iter = 0; iter < 2; iter++) {
        string T = S;

        for (int i = 0; i < N; i++)
            if (S[i] == '?')
                T[i] = '1';

        vector<int> ones_suffix(N + 1, 0);

        for (int i = N - 1; i >= 0; i--)
            ones_suffix[i] = ones_suffix[i + 1] + (T[i] == '1');

        int64_t count01 = 0, count10 = 0;
        int ones = 0, zeros = 0;

        for (int i = 0; i < N; i++)
            if (T[i] == '0') {
                count10 += ones;
                zeros++;
            } else {
                count01 += zeros;
                ones++;
            }

        best = min(best, X * count01 + Y * count10);
        ones = zeros = 0;

        for (int i = 0; i < N; i++)
            if (S[i] == '0') {
                zeros++;
            } else if (S[i] == '1') {
                ones++;
            } else {
                // 1 -> 0
                count01 -= zeros;
                count10 -= N - (i + 1) - ones_suffix[i + 1];
                count10 += ones;
                count01 += ones_suffix[i + 1];
                best = min(best, X * count01 + Y * count10);
                zeros++;
            }

        for (int i = 0; i < N; i++)
            if (S[i] != '?')
                S[i] = char('0' + '1' - S[i]);

        swap(X, Y);
    }

    cout << best << '\n';
}