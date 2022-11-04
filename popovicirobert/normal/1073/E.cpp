#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = 998244353;

int dp[20][1 << 10][10];
int cnt[20][1 << 10][10], p10[20];

inline void add(int &x, int y) {
    x += y;
    if(x >= MOD)
        x -= MOD;
}

inline void prec() {
    p10[0] = 1;
    for(int i = 1; i <= 19; i++) {
        p10[i] = (1LL * p10[i - 1] * 10) % MOD;
    }
    cnt[0][0][0] = 1;
    for(int i = 1; i <= 19; i++) {
        for(int conf = 0; conf < (1 << 10); conf++) {
            int s_dp = 0, s_cnt = 0;
            for(int j = 0; j < 10; j++) {
                add(s_dp, dp[i - 1][conf][j]);
                add(s_cnt, cnt[i - 1][conf][j]);
            }
            for(int j = 0; j < 10; j++) {
                if(conf & (1 << j)) {
                    add(dp[i][conf][j], (s_dp + 1LL * j * s_cnt * p10[i - 1]) % MOD);
                    add(cnt[i][conf][j], s_cnt);
                }
                else {
                    add(dp[i][conf ^ (1 << j)][j], (s_dp + 1LL * j * s_cnt * p10[i - 1]) % MOD);
                    add(cnt[i][conf ^ (1 << j)][j], s_cnt);
                }
            }
        }
    }
}

inline int get(int conf) {
    return __builtin_popcount(conf);
}

inline int solve(ll x, int k) {
    vector <int> dig;
    while(x > 0) {
        dig.push_back(x % 10);
        x /= 10;
    }
    reverse(dig.begin(), dig.end());
    int ans = 0;
    for(int j = (int) dig.size() - 1; j >= 1; j--) {
        for(int i = 1; i < 10; i++) {
            for(int conf = 0; conf < (1 << 10); conf++) {
                if(get(conf) <= k)
                    add(ans, dp[j][conf][i]);
            }
        }
    }
    int cur = 0;
    int cnf = 0;
    for(int i = 0; i < dig.size(); i++) {
        int nr = (int) dig.size() - i;
        for(int j = (i == 0); j < dig[i]; j++) {
            for(int conf = 0; conf < (1 << 10); conf++) {
                if(get(conf | cnf) <= k)
                    ans = (ans + 1LL * cur * cnt[nr][conf][j] + dp[nr][conf][j]) % MOD;
            }
        }
        cnf |= (1 << dig[i]);
        cur = (cur + 1LL * dig[i] * p10[nr - 1]) % MOD;
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int k;
    ll l, r;
    ios::sync_with_stdio(false);
    cin >> l >> r >> k;
    prec();
    cout << (solve(r + 1, k) - solve(l, k) + MOD) % MOD;
    //cin.close();
    //cout.close();
    return 0;
}