#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T1, typename T2>
bool maximize(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }

    return false;
}

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int INF = 1e9 + 5;

struct minion {
    int A, B, index;

    bool operator<(const minion &other) const {
        return B < other.B;
    }
};

void run_case() {
    int N, K;
    cin >> N >> K;
    vector<minion> minions(N);

    for (minion &m : minions)
        cin >> m.A >> m.B;

    for (int i = 0; i < N; i++)
        minions[i].index = i + 1;

    sort(minions.begin(), minions.end());
    vector<int> dp(K + 1, -INF);
    dp[0] = 0;
    vector<vector<bool>> previous(N + 1, vector<bool>(K + 1, false));

    for (int i = 0; i < N; i++) {
        vector<int> next_dp(K + 1, -INF);

        for (int k = 0; k <= K; k++) {
            if (maximize(next_dp[k], dp[k] + (K - 1) * minions[i].B))
                previous[i + 1][k] = false;

            if (k < K && maximize(next_dp[k + 1], dp[k] + minions[i].A + k * minions[i].B))
                previous[i + 1][k + 1] = true;
        }

        dp = next_dp;
    }

    dbg(dp[K]);
    vector<int> assignment(N, -1);

    for (int n = N, k = K, end = N; n > 0; n--)
        if (previous[n][k])
            assignment[--k] = minions[n - 1].index;
        else
            assignment[--end] = minions[n - 1].index;

    vector<int> solution;

    for (int k = 0; k < K - 1; k++)
        solution.push_back(assignment[k]);

    for (int k = K; k < N; k++) {
        solution.push_back(assignment[k]);
        solution.push_back(-assignment[k]);
    }

    solution.push_back(assignment[K - 1]);
    assert(int(solution.size()) == 2 * N - K);
    cout << solution.size() << '\n';
    output_vector(solution);
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