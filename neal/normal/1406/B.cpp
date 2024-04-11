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


void run_case() {
    int N;
    cin >> N;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int64_t> max_prod(N + 1), min_prod(N + 1);

    for (int i = 0; i < N; i++)
        max_prod[i + 1] = min_prod[i + 1] = A[i];

    for (int i = 1; i < N; i++) {
        max_prod[i + 1] = max(max_prod[i + 1], max_prod[i]);
        min_prod[i + 1] = min(min_prod[i + 1], min_prod[i]);
    }

    for (int iter = 1; iter < 5; iter++) {
        for (int i = N - 1; i >= iter; i--) {
            max_prod[i + 1] = max(A[i] * max_prod[i], A[i] * min_prod[i]);
            min_prod[i + 1] = min(A[i] * max_prod[i], A[i] * min_prod[i]);
        }

        for (int i = iter + 1; i < N; i++) {
            max_prod[i + 1] = max(max_prod[i + 1], max_prod[i]);
            min_prod[i + 1] = min(min_prod[i + 1], min_prod[i]);
        }
    }

    cout << max_prod[N] << '\n';
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