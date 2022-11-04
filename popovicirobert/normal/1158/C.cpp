#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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
}*/

/*int fact[], invfact[];

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

const int MAXN = (int) 5e5;

vector <int> g[5 * MAXN + 1];

void build(int nod, int left, int right, int n) {
    if(left == right) {
        return ;
    }

    int mid = (left + right) / 2;

    if(left == mid) {
        g[nod + n].push_back(left);
    }
    else {
        g[nod + n].push_back(2 * nod + n);
    }
    if(mid + 1 == right) {
        g[nod + n].push_back(right);
    }
    else {
        g[nod + n].push_back(2 * nod + 1 + n);
    }

    build(2 * nod, left, mid, n);
    build(2 * nod + 1, mid + 1, right, n);
}

void query(int nod, int left, int right, int l, int r, int id, int n) {
    if(l <= left && right <= r) {
        if(left == right) {
            g[id].push_back(left);
        }
        else {
            g[id].push_back(nod + n);
        }
        return ;
    }

    int mid = (left + right) / 2;

    if(l <= mid) query(2 * nod, left, mid, l, r, id, n);
    if(mid < r) query(2 * nod + 1, mid + 1, right, l, r, id, n);
}

int top[5 * MAXN + 1], sz;
int pos[5 * MAXN + 1];
bool vis[5 * MAXN + 1];

void dfs(int nod) {
    vis[nod] = 1;
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            dfs(it);
        }
    }
    top[++sz] = nod;
    pos[nod] = sz;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(i = 1; i <= 5 * n; i++) {
            g[i].clear();
        }

        vector <int> nxt(n + 1);
        for(i = 1; i <= n; i++) {
            cin >> nxt[i];
        }

        build(1, 1, n, n);

        for(i = 1; i <= n; i++) {
            if(nxt[i] != -1) {
                if(i + 1 <= nxt[i] - 1) {
                    query(1, 1, n, i + 1, nxt[i] - 1, i, n);
                }
                if(nxt[i] <= n) {
                    g[nxt[i]].push_back(i);
                }
            }
        }

        fill(vis, vis + 5 * n + 1, 0);
        sz = 0;

        for(i = 1; i <= 5 * n; i++) {
            if(vis[i] == 0) {
                dfs(i);
            }
        }

        vector <int> sol(n + 1);
        int cur = 0, ok = 1;

        for(i = 1; i <= sz && ok; i++) {
            if(top[i] <= n) {
                sol[top[i]] = ++cur;
            }
            for(auto it : g[top[i]]) {
                if(pos[it] > i) {
                    ok = 0;
                    break;
                }
            }
        }

        if(ok) {
            for(i = 1; i <= n; i++) {
                if(sol[i] == 0) {
                    sol[i] = ++cur;
                }
                cout << sol[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }

    return 0;
}