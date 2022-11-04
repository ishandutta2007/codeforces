#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

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
}*/

/*int fact[], invfact[];

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
}*/

using namespace std;

const int MAXN = (int) 3e5;

char str[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> str + 1;
    n = strlen(str + 1);

    vector <int> nxt(n + 1, n + 1);
    for(i = 1; i <= n; i++) {
        int j = i + 2;
        bool ok = 1;
        while(ok && j <= n) {
            int k = 1;
            while(j - 2 * k >= i && ok) {
                if(str[j] == str[j - k] && str[j] == str[j - 2 * k]) {
                    nxt[j - 2 * k] = j, ok = 0;
                }
                k++;
            }
            j++;
        }
    }

    vector <int> suff(n + 2, n + 1);
    for(i = n; i >= 1; i--) {
        suff[i] = min(suff[i + 1], nxt[i]);
    }

    ll ans = 0;
    for(i = 1; i <= n; i++) {
        ans += n - suff[i] + 1;
    }
    cout << ans;

    return 0;
}