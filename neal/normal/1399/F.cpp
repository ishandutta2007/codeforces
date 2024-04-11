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


struct segment {
    int L, R;
};

int N;
vector<segment> segs;
vector<vector<int>> segs_ending_at;
vector<int> dp;

int solve(int index) {
    if (dp[index] >= 0)
        return dp[index];

    segment &seg = segs[index];
    vector<int> location_dp(2 * N, 0);

    for (int x = 0; x < 2 * N; x++) {
        if (x > 0)
            location_dp[x] = max(location_dp[x], location_dp[x - 1]);

        for (int in : segs_ending_at[x]) {
            segment &other = segs[in];
            assert(other.R == x);

            if (in != index && seg.L <= other.L && other.R <= seg.R)
                location_dp[x] = max(location_dp[x], (other.L == 0 ? 0 : location_dp[other.L - 1]) + solve(in));
        }
    }

    return dp[index] = location_dp.back() + 1;
}

void run_case() {
    cin >> N;
    segs.resize(N);
    vector<int> sorted;

    for (segment &seg : segs) {
        cin >> seg.L >> seg.R;
        sorted.push_back(seg.L);
        sorted.push_back(seg.R);
    }

    sort(sorted.begin(), sorted.end());

    for (segment &seg : segs) {
        seg.L = int(lower_bound(sorted.begin(), sorted.end(), seg.L) - sorted.begin());
        seg.R = int(lower_bound(sorted.begin(), sorted.end(), seg.R) - sorted.begin());
    }

    segs_ending_at.assign(2 * N, {});

    for (int i = 0; i < N; i++)
        segs_ending_at[segs[i].R].push_back(i);

    segs.emplace_back();
    segs.back().L = 0;
    segs.back().R = 2 * N - 1;
    dp.assign(N + 1, -1);
    cout << solve(N) - 1 << '\n';
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