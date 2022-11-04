#include <bits/stdc++.h>
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
}

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
}*/

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        int n, m;

        cin >> n >> m;
        vector <int> cntl(n), cntc(m);
        vector <string> mat(n);

        for(i = 0; i < n; i++) {
            cin >> mat[i];
            for(j = 0; j < m; j++) {
                if(mat[i][j] == '.') {
                    cntl[i]++;
                    cntc[j]++;
                }
            }
        }

        int ans = n * m;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(ans > cntl[i] + cntc[j] - (mat[i][j] == '.')) {
                    ans = cntl[i] + cntc[j] - (mat[i][j] == '.');
                }
            }
        }

        cout << ans << "\n";

    }
    return 0;
}