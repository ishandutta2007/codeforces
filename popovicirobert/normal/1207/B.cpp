#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long


#if 0
const int MOD = ;

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
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector < vector <int> > b(n + 1, vector <int>(m + 1));
    auto a = b;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    vector < pair <int, int> > sol;
    for(i = 1; i < n; i++) {
        for(j = 1; j < m; j++) {
            if(b[i][j] + b[i + 1][j] + b[i][j + 1] + b[i + 1][j + 1] == 4) {
                sol.push_back({i, j});
                a[i][j] = a[i + 1][j] = a[i][j + 1] = a[i + 1][j + 1] = 1;
            }
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(a[i][j] != b[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << sol.size() << "\n";
    for(auto it : sol) {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}