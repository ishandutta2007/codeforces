#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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


const int INF = 1e9 + 5;
const int NM_MAX = 1e6 + 5;

int N, M;
vector<string> A;
vector<int> rows;
int dp[NM_MAX][8];

bool valid(int mask, int new_mask) {
    for (int i = 0; i + 2 <= M; i++) {
        int value = (mask >> i & 3) ^ (new_mask >> i & 3);

        if (__builtin_popcount(value) % 2 == 0)
            return false;
    }

    return true;
}

int solve(int row, int mask) {
    if (row >= N)
        return 0;

    int &ans = dp[row][mask];

    if (ans >= 0)
        return ans;

    ans = INF;

    for (int new_mask = 0; new_mask < 1 << M; new_mask++)
        if (valid(mask, new_mask)) {
            int cost = __builtin_popcount(new_mask ^ rows[row]);
            ans = min(ans, cost + solve(row + 1, new_mask));
        }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M;

    if (min(N, M) >= 4) {
        cout << -1 << '\n';
        return 0;
    }

    A.resize(N);

    for (auto &row : A)
        cin >> row;

    if (N < M) {
        vector<string> B(M);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                B[j] += A[i][j];

        swap(A, B);
        swap(N, M);
    }

    rows.assign(N, 0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            rows[i] += (A[i][j] - '0') << j;

    memset(dp, -1, sizeof(dp));
    int best = INF;

    for (int mask = 0; mask < 1 << M; mask++)
        best = min(best, solve(0, mask));

    cout << (best < INF ? best : -1) << '\n';
}