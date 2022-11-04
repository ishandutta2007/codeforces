#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


#if 1
const int MOD = (int) 1e9 + 7;

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

const int MAXN = (int) 1e6;

char str[3 * MAXN + 1];


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i, x;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        cin >> x >> str;

        int ans = strlen(str);
        int len = ans;
        for(int l = 1; l <= x; l++) {
            int val = str[l - 1] - '1';
            int cur_len = len;

            while(cur_len <= x && val > 0) {
                val--;
                for(int j = cur_len; j < cur_len + len - l; j++) {
                    str[j] = str[l + j - cur_len];
                }
                cur_len += len - l;
            }

            len = cur_len;
            ans = (ans + 1LL * (ans - l + MOD) * (str[l - 1] - '1')) % MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}