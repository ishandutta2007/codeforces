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

void run_case() {
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    int64_t A_sum = 0, B_sum = 0;

    for (auto &a : A) {
        cin >> a;
        A_sum += a;
    }

    for (auto &b : B) {
        cin >> b;
        B_sum += b;
    }

    if (B_sum < A_sum) {
        cout << "NO" << '\n';
        return;
    }

    vector<int64_t> combined;

    for (int iter = 0; iter < 2; iter++)
        for (int i = 0; i < N; i++) {
            combined.push_back(-A[i]);
            combined.push_back(B[i]);
        }

    int C = int(combined.size());
    vector<int64_t> prefix_sum(C + 1, 0);

    for (int i = 0; i < C; i++)
        prefix_sum[i + 1] = prefix_sum[i] + combined[i];

    int64_t maximum = -INF64;
    int64_t worst = INF64;

    for (int i = 1; i <= C; i++)
        if (i % 2 == 0)
            worst = min(worst, prefix_sum[i] - maximum);
        else
            maximum = max(maximum, prefix_sum[i]);

    if (worst < 0) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
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