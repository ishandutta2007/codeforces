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



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector < vector <int> > g(n + 1);
        for(i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector <bool> vis(n + 1);
        function < pair <int, bool>(int, int)> dfs = [&](int nod, int a) {
            pair <int, bool> ans = {1, (nod == a)};
            vis[nod] = 1;
            for(auto it : g[nod]) {
                if(vis[it] == 0) {
                    auto cur = dfs(it, a);
                    ans.first += cur.first;
                    ans.second |= cur.second;
                }
            }
            return ans;
        };

        vis[a] = 1;
        int sza = 0;
        for(auto it : g[a]) {
            if(vis[it] == 0) {
                auto cur = dfs(it, b);
                if(cur.second == 0) {
                    sza += cur.first;
                }
            }
        }

        fill(vis.begin(), vis.end(), 0);
        vis[b] = 1;

        int szb = 0;
        for(auto it : g[b]) {
            if(vis[it] == 0) {
                auto cur = dfs(it, a);
                if(cur.second == 0) {
                    szb += cur.first;
                }
            }
        }

        cout << 1LL * sza * szb << "\n";
    }

    return 0;
}