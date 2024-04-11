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


const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<pair<int64_t, int>> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());
    vector<int64_t> prefix_sum(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sum[i + 1] = prefix_sum[i] + A[i].first;

    int start = 2 - N % 3;
    int64_t best = -INF64;

    for (int plus = start; plus <= N; plus += 3) {
        int minus = N - plus;
        bool special = N > 1 && N % 2 != 0 && plus == (N + 1) / 2;

        if (!special) {
            best = max(best, prefix_sum[N] - 2 * prefix_sum[minus]);
            continue;
        }

        for (int i = 0; i < minus; i++)
            if (A[i].second % 2 == 0)
                special = false;

        for (int i = minus; i < N; i++)
            if (A[i].second % 2 != 0)
                special = false;

        if (!special) {
            best = max(best, prefix_sum[N] - 2 * prefix_sum[minus]);
            continue;
        }

        int64_t sum = prefix_sum[N] - 2 * prefix_sum[minus];
        sum -= 2 * (A[minus].first - A[minus - 1].first);
        best = max(best, sum);
    }

    cout << best << '\n';
}