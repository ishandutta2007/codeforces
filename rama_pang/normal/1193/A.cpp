#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MOD = 998244353;
/* dp[a][b] = a and b are bitmasks, a represnt vertices in set, b represent visitable vertices
  dp[a][b] = number of ways of permuting such that it is a topological prefix, and the sum of costs */
struct state {
    int cnt, sum;
    state(int C = 0, lint S = 0): sum(S % MOD), cnt(C) {}

    inline state & operator += (const state &o) {
        cnt += o.cnt;
        cnt %= MOD;
        sum += o.sum;
        sum %= MOD;
        return *this;
    }
};

vector<unordered_map<int, state>> dp;
vector<int> G, G_all; //bitmask representation
int N, M;

int main() {
    cin >> N >> M;
    G.resize(N), G_all.resize(N), dp.resize(1 << N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u] |= 1 << v;
        G_all[u] |= 1 << v;
        G_all[v] |= 1 << u;
    }
    dp[0][(1 << N) - 1] = state(1, 0);
    // cout << "OK" << endl;
    for (int mask = 0; mask < (1 << N); mask++) {
        for (auto &cur : dp[mask]) {
            int can = (1 << N) - 1; //if we pick c, the we cannot pick 0...c-1 as next candidates to prevent double counting
            for (int j = 0; j < N; j++) {
                can ^= 1 << j;
                if (cur.first & (1 << j)) {
                    int nxt_mask = mask | (1 << j); 
                    int nxt_nxt = (cur.first & can) | G_all[j];
                    nxt_nxt ^= nxt_nxt & nxt_mask;
                    lint cost = __builtin_popcount(mask & G[j]);
                    dp[nxt_mask][nxt_nxt] += state(cur.second.cnt, (lint)cur.second.sum + (lint)cur.second.cnt * cost);
                }
            }
        }
    }
    lint res = 0;
    for (auto &i : dp[(1 << N) - 1]) {
        res += i.second.sum;
        res %= MOD;
    }
    cout << res << "\n";
}