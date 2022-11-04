#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


#if 1
const int MOD = (int) 998244353;

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

const int MAXN = 2005;

#if 1
int fact[MAXN + 1], invfact[MAXN + 1];

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


int pref[MAXN + 1][MAXN + 1];
int suff[MAXN + 1][MAXN + 1];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;

    int num = 0;
    for(auto it : str) {
        num += (it == '?');
    }

    n = str.size();
    str = " " + str;

    pref[0][0] = 1;
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= n; j++) {
            if(str[i] == '(') {
                if(j > 0)
                    add(pref[i][j], pref[i - 1][j - 1]);
            }
            else if(str[i] == '?') {
                if(j > 0)
                    add(pref[i][j], pref[i - 1][j - 1]);
                add(pref[i][j], pref[i - 1][j]);
            }
            else {
                add(pref[i][j], pref[i - 1][j]);
            }
        }
    }

    suff[n + 1][0] = 1;
    for(i = n; i >= 1; i--) {
        for(j = 0; j <= n; j++) {
            if(str[i] == ')') {
                if(j > 0)
                    add(suff[i][j], suff[i + 1][j - 1]);
            }
            else if(str[i] == '?') {
                if(j > 0)
                    add(suff[i][j], suff[i + 1][j - 1]);
                add(suff[i][j], suff[i + 1][j]);
            }
            else {
                add(suff[i][j], suff[i + 1][j]);
            }
        }
    }

    for(i = n; i >= 1; i--) {
        for(j = n - 1; j >= 0; j--) {
            add(suff[i][j], suff[i][j + 1]);
        }
    }

    vector <int> ways(n + 1);
    ways[0] = lgput(2, num);

    for(i = 1; i <= n; i++) {
        if(str[i] == ')') continue;

        for(j = 1; j <= n; j++) {
            ways[j] = (ways[j] + 1LL * pref[i - 1][j - 1] * suff[i + 1][j]) % MOD;
        }
    }

    int ans = 0;
    for(i = 0; i <= n; i++) {
        //cerr << ways[i] << " ";
        if(i < n) {
            sub(ways[i], ways[i + 1]);
        }
        ans = (ans + 1LL * i * ways[i]) % MOD;
    }

    cout << ans;

    return 0;
}