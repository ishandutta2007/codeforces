#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

struct DSU {
    vector <int> par;
    stack <int> stk;
    int n;
    inline void init(int _n) {
        n = _n;
        par.resize(n + 1);
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

const int MAXN = 1000;

char mat[MAXN + 1][MAXN + 1];

vector <int> g[2 * MAXN + 1];
int dp[2 * MAXN + 1];

void dfs(int nod) {
    dp[nod] = 1;
    for(auto it : g[nod]) {
        if(dp[it] == 0) {
            dfs(it);
        }
        dp[nod] = max(dp[nod], dp[it] + 1);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    DSU dsu; dsu.init(n + m);
    for(i = 1; i <= n; i++) {
        cin >> mat[i] + 1;
        for(j = 1; j <= m; j++) {
            if(mat[i][j] == '=') {
                dsu.join(j + n, i);
            }
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            int a = dsu.root(i), b = dsu.root(j + n);
            if(mat[i][j] == '>') {
                g[a].push_back(b);
            }
            else if(mat[i][j] == '<') {
                g[b].push_back(a);
            }
        }
    }
    for(i = 1; i <= n + m; i++) {
        int x = dsu.root(i);
        if(dp[x] == 0) {
            dfs(x);
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            int a = dsu.root(i), b = dsu.root(j + n);
            if((dp[a] <= dp[b] && mat[i][j] == '>') || (dp[a] >= dp[b] && mat[i][j] == '<') || (dp[a] != dp[b] && mat[i][j] == '=')) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes" << "\n";
    for(i = 1; i <= n; i++) {
        cout << dp[dsu.root(i)] << " ";
    }
    cout << "\n";
    for(i = 1; i <= m; i++) {
        cout << dp[dsu.root(i + n)] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}