#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



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

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];
bool vis[MAXN + 1];
int par[MAXN + 1], w[MAXN + 1];
int low[MAXN + 1], lvl[MAXN + 1];

ll dp[MAXN + 1][2];

void dfs(int nod) {
    vis[nod] = 1, low[nod] = MAXN + 1;
    int num = 0;
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            lvl[it] = lvl[nod] + 1, par[it] = nod;
            dfs(it);
            low[nod] = min(low[nod], low[it]);
            num++;
        }
        else if(it != par[nod]) {
            low[nod] = min(low[nod], lvl[it]);
        }
    }

    dp[nod][1] = dp[nod][0] = w[nod];
    bool bad = 1;
    if(num == 0) {
        if(low[nod] < lvl[nod]) {
            bad = 0;
        }
    }
    else {
        if(low[nod] <= lvl[nod]) {
            bad = 0;
        }
    }

    for(auto it : g[nod]) {
        if(par[it] == nod) {
            vector <ll> cur(2);
            cur[1] = dp[nod][0] + dp[it][1];
            cur[1] = max(cur[1], dp[it][0] + dp[nod][1]);
            cur[0] = dp[nod][0] + dp[it][0];

            if(dp[it][0] >= 0) {
                bad = 0;
            }

            dp[nod][0] = max(dp[nod][0], cur[0]);
            dp[nod][1] = max(dp[nod][1], cur[1]);
        }
    }
    if(bad) {
        dp[nod][0] = -1e18;
    }
    //cerr << nod << " " << dp[nod][0] << " " << dp[nod][1] << "\n";
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for(i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int root;
    cin >> root;

    dfs(root);

    cout << max(dp[root][0], dp[root][1]);

    return 0;
}