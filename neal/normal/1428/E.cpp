#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
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

    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());

    auto get_cost = [](int64_t a, int64_t k) {
        int64_t mod = a % k;
        int64_t above = mod, below = k - above;
        return below * (a / k) * (a / k) + above * (a / k + 1) * (a / k + 1);
    };

    int64_t total = 0;

    for (auto &a : A)
        total += a * a;

    priority_queue<pair<int64_t, int64_t>> pq;
    vector<int64_t> counter(N, 1);

    for (int64_t i = 0; i < N; i++)
        pq.emplace(get_cost(A[i], 1) - get_cost(A[i], 2), i);

    for (int64_t iter = 0; iter < K - N; iter++) {
        auto top = pq.top(); pq.pop();
        total -= top.first;
        int64_t index = top.second;
        counter[index]++;
        pq.emplace(get_cost(A[index], counter[index]) - get_cost(A[index], counter[index] + 1), index);
    }

    cout << total << '\n';
}