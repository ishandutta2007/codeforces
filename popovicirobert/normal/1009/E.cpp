#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = 998244353;
const int MAXN = (int) 1e6;

int sp[MAXN + 1];
int p2[MAXN + 1], invp2[MAXN + 1];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
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

int dp[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sp[i] = sp[i - 1] + x;
        mod(sp[i]);
    }
    int inv = lgput(2, MOD - 2);
    p2[0] = invp2[0] = 1;
    for(i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2;
        mod(p2[i]);
        invp2[i] = (1LL * invp2[i - 1] * inv) % MOD;
    }
    int val = 0;
    for(i = 1; i <= n; i++) {
        if(i > 1)
            val = ((val + sp[i - 2]) * 2LL) % MOD;
        dp[i] = (2LL * dp[i - 1] + val + sp[i - 1] + sp[i]) % MOD;
    }
    cout << (dp[n] - dp[n - 1] + MOD) % MOD;
    //cin.close();
    //cout.close();
    return 0;
}