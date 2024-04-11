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

    int N, D;
    int64_t M;
    cin >> N >> D >> M;
    vector<int64_t> small, big;

    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;

        if (a > M)
            big.push_back(a);
        else
            small.push_back(a);
    }

    sort(small.rbegin(), small.rend());
    sort(big.rbegin(), big.rend());
    int S = int(small.size());
    int B = int(big.size());
    vector<int64_t> small_prefix(S + 1, 0);

    for (int i = 0; i < S; i++)
        small_prefix[i + 1] = small_prefix[i] + small[i];

    int64_t best = small_prefix[S];
    int64_t big_sum = 0;

    for (int64_t big_count = 1; big_count <= B; big_count++) {
        big_sum += big[big_count - 1];
        int64_t skip = (big_count - 1) * D;
        int64_t extra_big = B - big_count;
        int64_t small_skip = max(skip - extra_big, INT64_C(0));

        if (small_skip > S)
            continue;

        best = max(best, big_sum + small_prefix[S - small_skip]);
    }

    cout << best << '\n';
}