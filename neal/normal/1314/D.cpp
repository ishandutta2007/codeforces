#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):"; dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int N_MAX = 85;
const int INF = 1e9 + 5;
const int ITERATIONS = 5000;

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

int N, K;
int cost[N_MAX][N_MAX];

int solve() {
    vector<int> side(N);
    side[0] = 0;

    for (int i = 1; i < N; i++)
        side[i] = rng() % 2;

    vector<int> list[2];

    for (int i = 0; i < N; i++)
        list[side[i]].push_back(i);

    vector<int> dp(N, INF);
    dp[0] = 0;

    for (int k = 0; k < K; k++) {
        vector<int> next_dp(N, INF);

        for (int i = 0; i < N; i++)
            if (dp[i] < INF) {
                int other_side = 1 - side[i];

                for (int x : list[other_side])
                    next_dp[x] = min(next_dp[x], dp[i] + cost[i][x]);
            }

        dp = next_dp;
    }

    return dp[0];
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    int best = INF;

    for (int iter = 0; iter < ITERATIONS; iter++)
        best = min(best, solve());

    cout << best << '\n';
}