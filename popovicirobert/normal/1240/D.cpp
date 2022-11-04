#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 0
const int MOD = (int) ;

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

const int MAXN = (int) 3e5 + 5;

map <int, int> nxtX[MAXN + 1];
int nxt[MAXN + 1], a[MAXN + 1];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> q;

    while(q--) {
        cin >> n;

        for(i = 1; i <= n; i++) {
            cin >> a[i];
            nxtX[i].clear();
        }
        nxtX[n + 1].clear();

        for(i = n; i >= 1; i--) {
            if(i < n && a[i] == a[i + 1]) {
                nxt[i] = i + 1;
            }
            else {
                nxt[i] = nxtX[i + 1][a[i]];
            }

            if(nxt[i] != 0 && nxt[i] < n) {
                swap(nxtX[i], nxtX[nxt[i] + 1]);
                nxtX[i][a[nxt[i] + 1]] = nxt[i] + 1;
            }
        }

        vector <int> dp(n + 2);
        ll ans = 0;
        for(i = n; i >= 1; i--) {
            if(nxt[i] != 0) {
                dp[i] = 1 + dp[nxt[i] + 1];
            }
            ans += dp[i];
        }

        cout << ans << "\n";
    }

    return 0;
}