#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int u[MAXN + 1];

vector <int> g[MAXN + 1], rev[MAXN + 1];

inline int nxt(int x, int h) {
    return (x + 1) % h;
}

int top[MAXN + 1], sz;
bool vis[MAXN + 1];

void dfs(int nod) {
    vis[nod] = 1;
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            dfs(it);
        }
    }
    top[++sz] = nod;
}

vector <int> comp[MAXN + 1];
int id[MAXN + 1];

void dfs1(int nod) {
    vis[nod] = 1;
    comp[sz].push_back(nod);
    id[nod] = sz;
    for(auto it : rev[nod]) {
        if(vis[it] == 0) {
            dfs1(it);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, x, y, h;
    ios::sync_with_stdio(false);
    cin >> n >> m >> h;
    for(i = 1; i <= n; i++) {
        cin >> u[i];
    }
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        if(nxt(u[x], h) == u[y]) {
            g[x].push_back(y);
            //printf("%d %d\n" ,x,y);
            rev[y].push_back(x);
        }
        if(nxt(u[y], h) == u[x]) {
            g[y].push_back(x);
            //printf("%d %d\n" ,y,x);
            rev[x].push_back(y);
        }
    }
    for(i = 1; i <= n; i++) {
        if(vis[i] == 0)
            dfs(i);
    }
    for(i = 1; i <= n; i++) {
        g[i].clear();
    }
    memset(vis, 0, sizeof(vis));
    sz = 0;
    for(i = n; i >= 1; i--) {
        if(vis[top[i]] == 0) {
            sz++;
            dfs1(top[i]);
        }
    }
    for(i = 1; i <= n; i++) {
        for(auto it : rev[i]) {
            if(id[it] != id[i])
                g[id[it]].push_back(id[i]);
        }
    }
    int ans = 1e9;
    int pos = -1;
    for(i = 1; i <= sz; i++) {
        if(g[i].size() == 0) {
            if(ans > comp[i].size()) {
                ans = comp[i].size();
                pos = i;
            }
        }
    }
    cout << ans << "\n";
    for(auto it : comp[pos]) {
        cout << it << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}