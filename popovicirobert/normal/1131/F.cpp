#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

struct DSU {
    vector <int> par, sz;
    stack <int> stk;
    int n;
    inline void init(int _n) {
        n = _n;
        par.resize(n + 1), sz.resize(n + 1, 1);
    }
    int root(int x) {
        if(par[x] == 0)
            return x;
        return par[x] = root(par[x]);
    }
    inline void join(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            stk.push(x);
            par[x] = y;
            sz[y] += sz[x];
        }
        else {
            stk.push(-1);
        }
    }
    inline void undo() {
        if(stk.top() != -1) {
            par[stk.top()] = 0;
        }
        stk.pop();
    }
};

const int MAXN = 150000;

vector <int> g[2 * MAXN + 1];
int dp[2 * MAXN + 1], sol[MAXN + 1];

void dfs(int nod) {
    for(auto it : g[nod]) {
        dp[it] += dp[nod];
        dfs(it);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    DSU dsu; dsu.init(2 * n);
    for(i = n + 1; i <= 2 * n; i++) {
        dsu.sz[i] = 0;
    }
    int cur = n;
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x = dsu.root(x), y = dsu.root(y);
        cur++;
        dp[y] += dsu.sz[x];
        dsu.join(x, cur);
        dsu.join(y, cur);
        g[cur].push_back(x);
        g[cur].push_back(y);
    }
    dfs(cur);
    for(i = 1; i <= n; i++) {
        sol[dp[i] + 1] = i;
    }
    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}