#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long


#if 1
const int MOD = 998244353;

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



int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    vector <int> a(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector < vector <int> > dp(k + 1, vector <int>(n + 1));
    vector < vector <int> > sp = dp;

    int last = 0, ans = 0;
    for(int val = 1e5 / (k - 1); val > 0; val--) {
        for(i = 1; i <= n; i++) {
            sp[1][i] = i;
        }
        for(j = 2; j <= k; j++) {
            int pos = 1;
            for(i = j; i <= n; i++) {
                while(a[i] - a[pos] >= val) {
                    pos++;
                }
                dp[j][i] = sp[j - 1][pos - 1];
                sp[j][i] = dp[j][i];
                add(sp[j][i], sp[j][i - 1]);
            }
        }
        ans = (ans + 1LL * (sp[k][n] - last + MOD) * val) % MOD;
        last = sp[k][n];
    }
    cout << ans;

    return 0;
}