#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = 1000;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
    if(x < 0)
        x += MOD;
}

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

int sp1[MAXN + 1], sp2[MAXN + 1];
int pa, pb, k;
int S1, S2;

int dp[MAXN + 1][MAXN + 1];
bool vis[MAXN + 1][MAXN + 1];

int solve(int a, int ab) {
    if(ab >= k) {
        return ab;
    }
    if(vis[a][ab]) {
        return dp[a][ab];
    }
    vis[a][ab] = 1;
    if(a + ab >= k) {
        dp[a][ab] = (1LL * a * S1 + S2) % MOD;
        dp[a][ab] = (1LL * dp[a][ab] * pb) % MOD;
    }
    else {
        dp[a][ab] = (1LL * solve(a + 1, ab) * pa + 1LL * (solve(a, a + ab) + a) * pb) % MOD;
    }
    return dp[a][ab];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> k >> pa >> pb;
    int s = pa + pb;
    pa = (1LL * pa * lgput(s, MOD - 2)) % MOD;
    pb = (1LL * pb * lgput(s, MOD - 2)) % MOD;
    S1 = lgput(MOD + 1 - pa, MOD - 2);
    S2 = (1LL * pa * ((1LL * S1 * S1) % MOD)) % MOD;
    cout << solve(1, 0);
    //cin.close();
    //cout.close();
    return 0;
}