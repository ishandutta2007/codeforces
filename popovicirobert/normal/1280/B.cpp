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

const int MAXN = 100;

char mat[MAXN + 1][MAXN + 1];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        cin >> n >> m;

        for(i = 1; i <= n; i++) {
            cin >> mat[i] + 1;
        }

        int tot = 0;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                tot += (mat[i][j] == 'A');
            }
        }

        if(tot == 0) {
            cout << "MORTAL\n";
            continue;
        }
        if(tot == n * m) {
            cout << 0 << "\n";
            continue;
        }

        int c1 = 0, c2 = 0;
        for(i = 1; i <= n; i++) {
            c1 += (mat[i][1] == 'A');
            c2 += (mat[i][m] == 'A');
        }

        int l1 = 0, l2 = 0;
        for(j = 1; j <= m; j++) {
            l1 += (mat[1][j] == 'A');
            l2 += (mat[n][j] == 'A');
        }

        if(l1 == m || l2 == m || c1 == n || c2 == n) {
            cout << 1 << "\n";
            continue;
        }

        if(mat[1][1] == 'A' || mat[n][m] == 'A' || mat[1][m] == 'A' || mat[n][1] == 'A') {
            cout << 2 << "\n";
            continue;
        }

        int ans = -1;
        for(i = 1; i <= n; i++) {
            int cur = 0;
            for(j = 1; j <= m; j++) {
                cur += (mat[i][j] == 'A');
            }
            if(cur == m) {
                ans = 2;
            }
        }

        for(j = 1; j <= m; j++) {
            int cur = 0;
            for(i = 1; i <= n; i++) {
                cur += (mat[i][j] == 'A');
            }
            if(cur == n) {
                ans = 2;
            }
        }

        if(ans != -1) {
            cout << 2 << "\n";
            continue;
        }

        if(l1 + l2 + c1 + c2 > 0) {
            cout << 3 << "\n";
            continue;
        }

        cout << 4 << "\n";
    }

    return 0;
}