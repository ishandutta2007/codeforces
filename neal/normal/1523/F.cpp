#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


struct coord {
    int x, y;
};

struct quest {
    coord c;
    int time;

    bool operator<(const quest &other) const {
        return time < other.time;
    }
};

int manhattan(const coord &a, const coord &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}


const int INF = int(1.05e9) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<coord> towers(N);
    vector<quest> quests(M);

    for (auto &tower : towers)
        cin >> tower.x >> tower.y;

    for (auto &quest : quests)
        cin >> quest.c.x >> quest.c.y >> quest.time;

    sort(quests.begin(), quests.end());
    vector<vector<int>> precompute_dist(1 << N, vector<int>(N + M, INF));

    for (int mask = 0; mask < 1 << N; mask++)
        for (int from = 0; from < N; from++)
            if (mask >> from & 1) {
                for (int i = 0; i < N; i++)
                    precompute_dist[mask][i] = min(precompute_dist[mask][i], manhattan(towers[from], towers[i]));

                for (int q = 0; q < M; q++)
                    precompute_dist[mask][N + q] = min(precompute_dist[mask][N + q], manhattan(towers[from], quests[q].c));
            }

    vector<vector<int>> tower_dp(M + 1, vector<int>(1 << N, INF));

    auto update_dp = [&](int qs, int mask, int time) -> void {
        if (qs >= 0)
            tower_dp[qs][mask] = min(tower_dp[qs][mask], time);
    };

    for (int i = 0; i < N; i++)
        update_dp(0, 1 << i, 0);

    vector<int> current_q(1 << N, 0);

    auto dp_until = [&](int q, int time) -> void {
        for (int mask = 0; mask < 1 << N; mask++)
            for (int &qs = current_q[mask]; qs <= q && tower_dp[qs][mask] < time; qs++) {
                // update_dp(qs - 1, mask, time);

                // tower -> tower
                for (int i = 0; i < N; i++)
                    if ((mask >> i & 1) == 0) {
                        int travel = precompute_dist[mask][i];
                        update_dp(qs, mask | 1 << i, tower_dp[qs][mask] + travel);
                    }
            }
    };

    vector<vector<int>> quest_dp(M, vector<int>(1 << N, -INF));

    for (int q = 0; q < M; q++) {
        // tower -> tower
        dp_until(q, quests[q].time);

        // Start here,
        quest_dp[q][0] = max(quest_dp[q][0], 1);

        // tower -> quest
        for (int mask = 0; mask < 1 << N; mask++) {
            int travel = precompute_dist[mask][N + q];
            int cutoff = quests[q].time - travel;
            int low = -1, high = q;

            while (low < high) {
                int mid = low + (high - low + 1) / 2;

                if (tower_dp[mid][mask] <= cutoff)
                    low = mid;
                else
                    high = mid - 1;
            }

            if (low >= 0)
                quest_dp[q][mask] = max(quest_dp[q][mask], low + 1);
        }

        // quest -> quest
        for (int p = 0; p < q; p++)
            for (int mask = 0; mask < 1 << N; mask++) {
                int travel = min(precompute_dist[mask][N + q], manhattan(quests[p].c, quests[q].c));

                if (quests[p].time + travel <= quests[q].time)
                    quest_dp[q][mask] = max(quest_dp[q][mask], quest_dp[p][mask] + 1);
            }

        // quest -> tower
        for (int mask = 0; mask < 1 << N; mask++)
            for (int i = 0; i < N; i++) {
                int travel = min(precompute_dist[mask][i], manhattan(quests[q].c, towers[i]));
                update_dp(quest_dp[q][mask], mask | 1 << i, quests[q].time + travel);
            }
    }

    int answer = 0;

    for (int q = 0; q < M; q++)
        for (int mask = 0; mask < 1 << N; mask++)
            answer = max(answer, quest_dp[q][mask]);

    cout << answer << '\n';
}