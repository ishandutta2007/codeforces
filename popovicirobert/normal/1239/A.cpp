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



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    /*for(int n = 1; n <= 5; n++) {
        for(int m = 1; m <= 5; m++) {
            vector < vector <int> > mat(n, vector <int>(m));
            int ans = 0;

            for(int conf = 0; conf < (1 << (n * m)); conf++) {
                int sz = 0;
                for(i = 0; i < n; i++) {
                    for(j = 0; j < m; j++) {
                        mat[i][j] = ((conf & (1 << sz)) > 0);
                        sz++;
                    }
                }

                bool flag = 1;
                for(i = 0; i < n; i++) {
                    for(j = 0; j < m; j++) {
                        int cnt = 0;
                        if(i > 0 && mat[i][j] == mat[i - 1][j]) {
                            cnt++;
                        }
                        if(j > 0 && mat[i][j] == mat[i][j - 1]) {
                            cnt++;
                        }
                        if(i + 1 < n && mat[i][j] == mat[i + 1][j]) {
                            cnt++;
                        }
                        if(j + 1 < m && mat[i][j] == mat[i][j + 1]) {
                            cnt++;
                        }
                        if(cnt > 1) {
                            flag = 0;
                        }
                    }
                }

                ans += flag;
            }

            cerr << ans << " ";
        }
        cerr << "\n";
    }*/

    cin >> n >> m;

    if(n > m) {
        swap(n, m);
    }

    int a = 2, b = 4, ans;

    if(n == 1) ans = 2;
    if(n == 2) ans = 4;

    for(i = 3; i <= n; i++) {
        ans = a + b;
        mod(ans);
        a = b;
        b = ans;
    }

    a = 0, b = 2;

    for(i = 2; i <= m; i++) {
        int cur = a + b;
        mod(cur);
        add(ans, b);
        a = b;
        b = cur;
    }

    cout << ans;

    return 0;
}