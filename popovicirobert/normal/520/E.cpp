#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e5;

int fact[MAXN + 1], invfact[MAXN + 1];
int p10[MAXN + 1], sp[MAXN + 1];
char str[MAXN + 1];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans= (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
    p10[0] = 1;
    for(int i = 1; i <= n; i++) {
        sp[i] = sp[i - 1] + str[i] - '0';
        p10[i] = (1LL * p10[i - 1] * 10) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k)
        return 0;
    return (1LL * fact[n] * ((1LL * invfact[k] * invfact[n - k]) % MOD)) % MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> str + 1;
    prec(n);
    int ans = 0;
    for(int len = 1; len < n; len++) {
        int cur = (1LL * p10[len - 1] * sp[n - len]) % MOD;
        cur = (1LL * cur * comb(n - len - 1, k - 1)) % MOD;
        ans += cur;
        mod(ans);
        //printf("%d %d %d %d\n" ,len,sp[n - len],comb(n - len - 1, k - 1),ans);
    }
    for(int len = 1; len <= n; len++) {
        int cur = (1LL * p10[len - 1] * (str[n - len + 1] - '0')) % MOD;
        cur = (1LL * cur * comb(n - len, k)) % MOD;
        ans += cur;
        mod(ans);
        //printf("%d %d %d %d\n" ,len,str[n - len + 1] - '0',comb(n - len, k),ans);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}