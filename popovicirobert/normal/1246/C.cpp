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

const int MAXN = 2005;

char mat[MAXN + 1][MAXN + 1];
int u[MAXN + 1][MAXN + 1], l[MAXN + 1][MAXN + 1];

int cnt_d[MAXN + 1][MAXN + 1], cnt_r[MAXN + 1][MAXN + 1];
int sp_l[MAXN + 1][MAXN + 1], sp_u[MAXN + 1][MAXN + 1];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for(i = 1; i <= n; i++) {
        cin >> mat[i] + 1;
    }

    if(max(n, m) == 1) {
        cout << 1;
        return 0;
    }

    for(i = n; i >= 1; i--) {
        for(j = m; j >= 1; j--) {
            cnt_r[i][j] = cnt_r[i][j + 1] + (mat[i][j] == 'R');
            cnt_d[i][j] = cnt_d[i + 1][j] + (mat[i][j] == 'R');
        }
    }

    //u[1][1] = l[1][1] = 1;
    add(sp_l[1][1], 1);
    sub(sp_l[1][m - cnt_r[1][1] + 1], 1);

    add(sp_u[1][1], 1);
    sub(sp_u[n - cnt_d[1][1] + 1][1], 1);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            /*for(int k = i + 1; k <= n - cnt_d[i + 1][j]; k++) {
                add(u[k][j], l[i][j]);
            }
            for(int k = j + 1; k <= m - cnt_r[i][j + 1]; k++) {
                add(l[i][k], u[i][j]);
            }*/

            add(sp_u[i][j], sp_u[i - 1][j]);
            add(sp_l[i][j], sp_l[i][j - 1]);


            l[i][j] = sp_l[i][j];
            u[i][j] = sp_u[i][j];

            if((i == n && j == m) || (i == 1 && j == 1)) continue;

            add(sp_u[i + 1][j], l[i][j]);
            sub(sp_u[n - cnt_d[i + 1][j] + 1][j], l[i][j]);

            add(sp_l[i][j + 1], u[i][j]);
            sub(sp_l[i][m - cnt_r[i][j + 1] + 1], u[i][j]);
        }
    }

    if(mat[n][m] == 'R') {
        cout << 0;
        return 0;
    }
    cout << (l[n][m] + u[n][m]) % MOD;

    return 0;
}