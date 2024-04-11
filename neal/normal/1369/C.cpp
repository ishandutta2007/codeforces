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
    int N, K;
    cin >> N >> K;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    vector<int> W(K);

    for (auto &w : W)
        cin >> w;

    sort(W.rbegin(), W.rend());
    int first = 0, last = N - 1;
    int64_t answer = 0;

    for (int w : W)
        if (w > 1) {
            answer += A[first];
            first += w - 1;
        }

    reverse(W.begin(), W.end());

    for (int w : W)
        answer += (w == 1 ? 2 : 1) * A[last--];

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