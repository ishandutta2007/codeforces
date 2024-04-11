#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
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

    auto &&is_square = [](int64_t x) {
        int64_t s = int64_t(sqrt(x));
        return x == s * s;
    };

    int N;
    cin >> N;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int64_t> square_cost(N, INF64);
    vector<int64_t> non_cost(N, INF64);

    for (int i = 0; i < N; i++)
        for (int64_t x = A[i] - 5; x <= A[i] + 5; x++)
            if (x >= 0 && !is_square(x))
                non_cost[i] = min(non_cost[i], abs(A[i] - x));

    for (int i = 0; i < N; i++) {
        int64_t s = int64_t(sqrt(A[i]));
        square_cost[i] = min(A[i] - s * s, (s + 1) * (s + 1) - A[i]);
    }

    int S = 0;

    for (auto &a : A)
        S += is_square(a);

    vector<int64_t> cheapest;
    int64_t need = 0;

    if (S < N / 2) {
        need = N / 2 - S;

        for (int i = 0; i < N; i++)
            if (square_cost[i] > 0)
                cheapest.push_back(square_cost[i]);
    } else {
        need = S - N / 2;

        for (int i = 0; i < N; i++)
            if (non_cost[i] > 0)
                cheapest.push_back(non_cost[i]);
    }

    sort(cheapest.begin(), cheapest.end());
    cout << accumulate(cheapest.begin(), cheapest.begin() + need, 0LL) << '\n';
}