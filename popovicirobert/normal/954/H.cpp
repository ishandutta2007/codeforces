#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = 5000;

int a[MAXN + 1];
int cnt[MAXN + 1], invcnt[MAXN + 1];

int dp[MAXN + 1][2 * MAXN];
int up[2 * MAXN], down[2 * MAXN];

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

bool vis[MAXN + 1][2 * MAXN];
int n;

int solve(int lvl, int k) {
    if(lvl == 0)
        return 0;
    if(k == 0)
        return dp[lvl][k] = 1;
    if(vis[lvl][k])
        return dp[lvl][k];
    vis[lvl][k] = 1;
    if(lvl + k <= n)
        dp[lvl][k] = (1LL * (a[lvl + 1] - 1) * ((1LL * cnt[lvl + k] * invcnt[lvl + 1]) % MOD)) % MOD;
    dp[lvl][k] = (dp[lvl][k] + solve(lvl - 1, k - 1)) % MOD;
    return dp[lvl][k];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, lvl, k;
    ios::sync_with_stdio(false);
    cin >> n;
    cnt[1] = 1;
    for(i = 2; i <= n; i++) {
        cin >> a[i];
        cnt[i] = (1LL * cnt[i - 1] * a[i]) % MOD;
    }
    for(i = 1; i <= n; i++) {
        invcnt[i] = lgput(cnt[i], MOD - 2);
    }
    for(k = 1; k <= n; k++) {
        for(lvl = 1; lvl <= n - k; lvl++) {
            down[k] = (down[k] + cnt[lvl + k]) % MOD;
        }
    }
    for(k = 1; k <= 2 * n - 2; k++) {
        for(lvl = 1; lvl <= n; lvl++) {
            int val = 0;
            if(lvl + k <= n) {
                val = (1LL * (a[lvl + 1] - 1) * ((1LL * cnt[lvl + k] * invcnt[lvl + 1]) % MOD)) % MOD;
            }
            up[k] = (up[k] + 1LL * (solve(lvl, k) - val + MOD) * cnt[lvl]) % MOD;
        }
    }
    for(k = 1; k <= 2 * n - 2; k++) {
        cout << (1LL * (down[k] + up[k]) * lgput(2, MOD - 2)) % MOD << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}