#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

/////////////////
// C(n, x) * x ^ k ==> alegi x muncitori din n si atribui k job-uri acestora
// A(n, i) * 2 ^ (n - i) * Stirling(k, i)
// fixam cati muncitori primesc sigur job(i), restul de n - i pot sa faca parte sau nu din cei x
// atribuim cele k joburi celor i muncitori
/////////////////

const int MOD = (int) 1e9 + 7;
const int MAXK = 5000;

int dp[MAXK + 1][MAXK + 1];
//int invfact[MAXK + 1];

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

inline int comb(int n, int k) {
    int ans = 1;
    for(int i = n - k + 1; i <= n; i++) {
        ans = (1LL * ans * i) % MOD;
    }
    return ans;
    //return (1LL * ans * invfact[k]) % MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, j;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    dp[1][1] = 1;
    for(i = 2; i <= k; i++) {
        for(j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + 1LL * dp[i - 1][j] * j) % MOD;
        }
    }
    /*int fact = 1;
    invfact[0] = 1;
    for(i = 1; i <= k; i++) {
        fact = (1LL * fact * i) % MOD;
        invfact[i] = lgput(fact, MOD - 2);
    }*/
    int p2 = lgput(2, n - 1);
    int ans = 0;
    for(i = 1; i <= k; i++) {
        int cur = (1LL * p2 * dp[k][i]) % MOD;
        cur = (1LL * cur * comb(n, i)) % MOD;
        //printf("%d %d %d\n" ,p2,comb(n, i),dp[k][i]);
        ans += cur;
        mod(ans);
        p2 = lgput(2, n - i - 1);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}