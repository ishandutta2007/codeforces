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
    int C = (N + 1) / 2, F = N / 2;
    assert(C + F == N);
    vector<int64_t> A(C);
    int64_t A_sum = 0;

    for (auto &a : A) {
        cin >> a;
        A_sum += a;
    }

    int64_t X;
    cin >> X;

    if (X > 0) {
        if (A_sum + X * F > 0)
            cout << N << '\n';
        else
            cout << -1 << '\n';

        return 0;
    }

    vector<int> longest(C, -1);
    int64_t A_suffix = 0;

    for (int i = C - 1; i >= 0; i--) {
        A_suffix += A[i];

        if (A_suffix <= 0) {
            longest[i] = -1;
            continue;
        }

        int64_t extra = X == 0 ? F : min((A_suffix - 1) / (-X), int64_t(F));
        longest[i] = C + int(extra) - i;
    }

    int K = -1;
    int minimum = N;

    for (int i = 0; i < C; i++) {
        minimum = min(minimum, longest[i]);

        if (minimum >= N - i) {
            K = N - i;
            break;
        }
    }

    cout << K << '\n';
}