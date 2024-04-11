#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int64_t INF64 = (int64_t) 2e18 + 5;

int N;

int prv(int index) {
    return index == 0 ? N - 1 : index - 1;
}

int nxt(int index) {
    return index == N - 1 ? 0 : index + 1;
}

void run_case() {
    cin >> N;
    vector<int64_t> A(N), B(N);

    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];

    vector<int64_t> diffs(N);
    int64_t sum = 0;

    for (int i = 0; i < N; i++) {
        diffs[i] = max(A[i] - B[prv(i)], INT64_C(0));
        sum += diffs[i];
    }

    int64_t best = INF64;

    for (int first = 0; first < N; first++)
        best = min(best, sum - diffs[first] + A[first]);

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