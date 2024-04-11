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

const int MAXN = (int) 1e6;

vector <int> g[MAXN + 1], gr[MAXN + 1], ord;
int idc[MAXN + 1];
bool vis[MAXN + 1];

void dfs(int nod) {
    vis[nod] = 1;
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            dfs(it);
        }
    }
    ord.push_back(nod);
}

void dfs1(int nod, int id) {
    vis[nod] = 1;
    idc[nod] = id;

    for(auto it : gr[nod]) {
        if(vis[it] == 0) {
            dfs1(it, id);
        }
    }
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        int n, m;

        cin >> n >> m;

        for(i = 1; i <= n; i++) {
            g[i].clear();
            gr[i].clear();
            vis[i] = 0;
        }

        for(i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            gr[y].push_back(x);
        }

        ord.clear();
        for(i = 1; i <= n; i++) {
            if(vis[i] == 0) {
                dfs(i);
            }
        }

        for(i = 1; i <= n; i++) {
            vis[i] = 0;
        }

        int id = 0;
        for(i = n - 1; i >= 0; i--) {
            if(vis[ord[i]] == 0) {
                dfs1(ord[i], ++id);
            }
        }

        if(id == 1) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";

            vector <int> deg(id + 1);

            for(i = 1; i <= n; i++) {
                for(auto it : g[i]) {
                    if(idc[it] != idc[i])
                        deg[idc[i]]++;
                }
            }

            int comp;
            for(i = 1; i <= id; i++) {
                if(deg[i] == 0) {
                    comp = i;
                }
            }

            for(i = 1; i <= n; i++) {
                vis[i] = 0;
            }

            function <void(int)> solve = [&](int nod) {
                vis[nod] = 1;
                for(auto it : g[nod]) {
                    if(vis[it] == 0) {
                        solve(it);
                    }
                }
            };


            for(i = 1; i <= n; i++) {
                if(idc[i] == comp) {
                    solve(i);
                    break;
                }
            }

            int cnt = 0;
            for(i = 1; i <= n; i++) {
                cnt += vis[i];
            }

            cout << cnt << " " << n - cnt << "\n";
            for(i = 1; i <= n; i++) {
                if(vis[i]) {
                    cout << i << " ";
                }
            }
            cout << "\n";
            for(i = 1; i <= n; i++) {
                if(vis[i] == 0) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}