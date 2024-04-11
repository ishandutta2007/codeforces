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

const int MAXN = (int) 1e5;

vector < pair <int, int> > g[MAXN + 1];
vector <int> leaves[MAXN + 1];

struct Edge {
    int x, y, z;
};

vector <Edge> ops;
int par[MAXN + 1];

void dfs1(int nod) {
    int sz = 0;
    for(auto it : g[nod]) {
        if(it.first != par[nod]) {
            par[it.first] = nod;
            dfs1(it.first);
            leaves[nod].push_back(leaves[it.first][0]);
            sz++;
        }
    }
    if(sz == 0) {
        leaves[nod].push_back(nod);
        return ;
    }
    leaves[nod].resize(min(2, (int) leaves[nod].size()));
}

int root;

inline void solve(int nod, int val) {
    if(leaves[nod].size() == 1) {
        ops.push_back({root, nod, val});
        return ;
    }
    ops.push_back({root, leaves[nod][0], val / 2});
    ops.push_back({root, leaves[nod][1], val / 2});
    ops.push_back({leaves[nod][0], leaves[nod][1], -val / 2});
}

inline void add(int nod, int val) {
    solve(nod, val);
    if(par[nod] != root) {
        solve(par[nod], -val);
    }
}

void dfs2(int nod) {
    for(auto it : g[nod]) {
        if(it.first != par[nod]) {
            add(it.first, it.second);
            dfs2(it.first);
        }
    }
}

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    for(i = 1; i <= n; i++) {
        if(g[i].size() == 2) {
            cout << "NO";
            return 0;
        }
    }

    if(n == 2) {
        cout << "YES\n1\n" << 1 << " " << 2 << " " << g[1].back().second;
        return 0;
    }

    root = 1;
    while(g[root].size() != 1) root++;

    dfs1(root);
    dfs2(root);

    cout << "YES\n";
    cout << ops.size() << "\n";
    for(auto it : ops) {
        cout << it.x << " " << it.y << " " << it.z << "\n";
    }

    return 0;
}