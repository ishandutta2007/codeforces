#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long


#if 0
const int MOD = ;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}
#endif

#if 0
int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}
#endif

using namespace std;

const int MAXN = 2000;

int dp[MAXN + 1][MAXN + 1], cnt[MAXN + 1][MAXN + 1];
char str[MAXN + 1];

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> str + 1;
    n = strlen(str + 1);

    for(i = 1; i <= n; i++) {
        vector <int> cur(2);
        cur[0] = 0; cur[1] = -2 * n;
        for(j = i; j <= n; j++) {
            vector <int> aux(2);
            if(str[j] == '0') {
                aux[0] = cur[0] + 1;
                aux[1] = cur[1];
            }
            else {
                aux[0] = cur[0];
                aux[1] = max(cur[0] + 1, cur[1] + 1);
            }
            swap(aux, cur);
            dp[i][j] = max(cur[0], cur[1]);
            cnt[i][j] = cnt[i][j - 1] + (str[j] == '0');
        }
    }

    vector <int> mx(n + 1, 1);
    for(i = 1; i <= n; i++) {
        for(j = i + 1; j <= n; j++) {
            if(dp[i][j] - cnt[i][j] <= dp[i + 1][j] - cnt[i + 1][j]) {
                mx[i] = 0;
            }
        }
        for(j = i - 1; j > 0; j--) {
            if(dp[j][i] - cnt[j][i] <= dp[j][i - 1] - cnt[j][i - 1]) {
                mx[i] = 0;
            }
        }
    }
    for(i = 1; i <= n; i++) {
        if(str[i] == '0') cout << '0';
        else cout << (char) (1 - mx[i] + '0');
    }

    return 0;
}