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
    int64_t N;
    int M;
    cin >> N >> M;
    vector<pair<int, int>> flowers(M);

    for (auto &flower : flowers)
        cin >> flower.first >> flower.second;

    sort(flowers.rbegin(), flowers.rend());

    if (N == 1) {
        cout << flowers.front().first << '\n';
        return;
    }

    vector<int64_t> a_sum(M + 1, 0);

    for (int i = 0; i < M; i++)
        a_sum[i + 1] = a_sum[i] + flowers[i].first;

    int64_t best = 0;

    for (int b = 0; b < M; b++) {
        int repeat = flowers[b].second;
        int64_t total = flowers[b].first;
        int replace = int(lower_bound(flowers.begin(), flowers.end(), make_pair(repeat, -1), greater<pair<int, int>>()) - flowers.begin());

        if (replace - (replace > b) > N - 1) {
            replace = int(N) - 1;

            if (replace - (replace > b) < N - 1)
                replace++;
        }

        int64_t count = 1 + replace - (replace > b);
        total += a_sum[replace] - (replace > b ? flowers[b].first : 0);
        total += (N - count) * repeat;
        best = max(best, total);
    }

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