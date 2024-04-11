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

const int INF = 1e9;

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector < vector <int> > g(n + 1);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if(ch == '1') {
                g[i].push_back(j);
            }
        }
    }

    vector < vector <int> > dst(n + 1, vector <int>(n + 1));
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            dst[i][j] = INF;
        }
        queue <int> Q; Q.push(i);
        dst[i][i] = 0;
        while(Q.size()) {
            int nod = Q.front();
            Q.pop();
            for(auto it : g[nod]) {
                if(dst[i][it] == INF) {
                    Q.push(it);
                    dst[i][it] = dst[i][nod] + 1;
                }
            }
        }
    }

    cin >> m;
    vector <int> dp(m + 1), last(n + 1), from(m + 1);
    vector <int> x(m + 1);

    cin >> x[1];
    dp[1] = last[x[1]] = 1;

    for(i = 2; i <= m; i++) {
        cin >> x[i];
        dp[i] = INF;
        for(j = 1; j <= n; j++) {
            if(last[j] > 0 && i - last[j] == dst[j][x[i]]) {
                if(dp[i] > dp[last[j]] + 1) {
                    dp[i] = dp[last[j]] + 1;
                    from[i] = last[j];
                }
            }
        }
        last[x[i]] = i;
    }

    vector <int> sol;
    while(m > 0) {
        sol.push_back(x[m]);
        m = from[m];
    }
    cout << sol.size() << "\n";
    while(sol.size()) {
        cout << sol.back() << " ";
        sol.pop_back();
    }

    return 0;
}