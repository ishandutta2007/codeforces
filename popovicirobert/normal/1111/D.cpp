#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;
const int MOD = (int) 1e9 + 7;

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

char str[MAXN + 1];
int fr[200];

int fact[MAXN + 1], invfact[MAXN + 1];
int dp[MAXN + 1];

int sol[200][200];
int aux[MAXN / 2 + 1];

inline void prec(int n) {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        invfact[i] = lgput(fact[i], MOD - 2);
    }
    dp[0] = 1;
    for(int i = 0; i <= 200; i++) {
        if(fr[i] > 0) {
            for(int j = n / 2; j >= fr[i]; j--) {
                dp[j] += dp[j - fr[i]];
                mod(dp[j]);
            }
        }
    }
    for(int a = 0; a < 200; a++) {
        if(fr[a]) {
            for(int b = a; b < 200; b++) {
                if(fr[b]) {
                    for(int i = 0; i <= n / 2; i++) {
                        if(i < fr[a]) {
                            aux[i] = dp[i];
                        }
                        else {
                            aux[i] = dp[i] - aux[i - fr[a]];
                            aux[i] += MOD;
                            mod(aux[i]);
                        }
                    }
                    if(a != b) {
                        for(int i = fr[b]; i <= n / 2; i++) {
                            aux[i] -= aux[i - fr[b]];
                            aux[i] += MOD;
                            mod(aux[i]);
                        }
                    }
                    sol[a][b] = aux[n / 2];
                }
            }
        }
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * ((1LL * invfact[k] * invfact[n - k]) % MOD)) % MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> str + 1;
    int n = strlen(str + 1);
    for(i = 1; i <= n; i++) {
        fr[str[i]]++;
    }
    prec(n);
    int prd = 1;
    for(i = 0; i < 200; i++) {
        if(fr[i] > 0) {
            prd = (1LL * prd * fact[fr[i]]) % MOD;
        }
    }
    prd = lgput(prd, MOD - 2);
    cin >> q;
    while(q > 0) {
        q--;
        int x, y;
        cin >> x >> y;
        int ans;
        if(str[x] == str[y]) {
            if(fr[str[x]] > n / 2) {
                ans = 0;
            }
            else {
                int cur = sol[str[x]][str[y]];
                int aux = (1LL * prd * fact[fr[str[x]]]) % MOD;
                ans = (1LL * cur * (1LL * (1LL * fact[n / 2] * fact[n / 2 - fr[str[x]]] % MOD) * aux % MOD)) % MOD;
                ans = (1LL * ans * 1LL * comb(n / 2, fr[str[x]])) % MOD;
            }
        }
        else {
            if(str[x] > str[y]) {
                swap(x, y);
            }
            if(fr[str[x]] + fr[str[y]] > n / 2) {
                ans = 0;
            }
            else {
                int cur = sol[str[x]][str[y]];
                int aux = (1LL * prd * fact[fr[str[x]]]) % MOD;
                aux = (1LL * aux * fact[fr[str[y]]]) % MOD;
                ans = (1LL * cur * (1LL * (1LL * fact[n / 2] * fact[n / 2 - fr[str[x]] - fr[str[y]]] % MOD) * aux % MOD)) % MOD;
                ans = (1LL * ans * (1LL * comb(n / 2, fr[str[x]] + fr[str[y]]) * comb(fr[str[x]] + fr[str[y]], fr[str[x]]) % MOD)) % MOD;
            }
        }
        cout << (2LL * ans) % MOD << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}