#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



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

#if 1
const int MAXN = 4000;

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

int dpl[MAXN + 1][MAXN + 1][2], dpc[MAXN + 1][MAXN + 1][2];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, h, w, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    prec(MAXN);

    cin >> h >> w >> n;

    vector <bool> visl(h + 1), visc(w + 1);
    for(i = 1; i <= n; i++) {
        int l1, c1, l2, c2;
        cin >> l1 >> c1 >> l2 >> c2;
        visl[l1] = visl[l2] = visc[c1] = visc[c2] = 1;
    }

    int num_l = 0, num_c = 0;
    for(i = 1; i <= h; i++) {
        num_l += 1 - visl[i];
    }
    for(i = 1; i <= w; i++) {
        num_c += 1 - visc[i];
    }

    dpc[0][0][0] = 1;
    for(i = 1; i <= w; i++) {
        for(j = 0; j <= w; j++) {
            for(int k = 0; k < 2; k++) {
                add(dpc[i][j][0], dpc[i - 1][j][k]);
            }
            if(visc[i] == 0 && visc[i - 1] == 0 && i > 1 && j > 0) {
                add(dpc[i][j][1], dpc[i - 1][j - 1][0]);
            }
        }
    }
    dpl[0][0][0] = 1;
    for(i = 1; i <= h; i++) {
        for(j = 0; j <= h; j++) {
            for(int k = 0; k < 2; k++) {
                add(dpl[i][j][0], dpl[i - 1][j][k]);
            }
            if(visl[i] == 0 && visl[i - 1] == 0 && i > 1 && j > 0) {
                add(dpl[i][j][1], dpl[i - 1][j - 1][0]);
            }
        }
    }

    int ans = 0;
    for(int a = 0; a <= w; a++) { // 1x2
        for(int b = 0; b <= h; b++) { // 2x1
            int cur = (1LL * comb(num_c - 2 * a, b) * comb(num_l - 2 * b, a)) % MOD;
            mul(cur, fact[a]);
            mul(cur, fact[b]);
            for(i = 0; i < 2; i++) {
                for(j = 0; j < 2; j++) {
                    ans = (ans + 1LL * cur * (1LL * dpc[w][a][i] * dpl[h][b][j] % MOD)) % MOD;
                }
            }
        }
    }
    cout << ans;

    return 0;
}