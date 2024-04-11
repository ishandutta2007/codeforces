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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    for (int i = 0; i < N; i++)
        A.push_back(A[i]);

    vector<int64_t> prefix_sum(2 * N + 1, 0);
    prefix_sum[1] = A[0];

    for (int i = 2; i <= 2 * N; i++)
        prefix_sum[i] = prefix_sum[i - 2] + A[i - 1];

    int64_t best = 0;

    for (int end = N + 1; end <= 2 * N; end++)
        best = max(best, prefix_sum[end] - prefix_sum[end - (N + 1)]);

    cout << best << '\n';
}