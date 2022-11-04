#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 3e5;

vector < pair <int, int> > g[MAXN + 1];
bool vis[MAXN + 1];

int lvl[MAXN + 1], low[MAXN + 1];
bool block[MAXN + 1];

void dfs(int nod, int p) {
    vis[nod] = 1;
    low[nod] = MAXN;
    for(auto it : g[nod]) {
        if(vis[it.first] == 0) {
            lvl[it.first] = lvl[nod] + 1;
            low[it.first] = lvl[it.first];
            dfs(it.first, nod);
            if(low[it.first] > lvl[nod]) {
                block[it.second] = 1;
            }
            low[nod] = min(low[nod], low[it.first]);
        }
        else if(it.first != p) {
            low[nod] = min(low[nod], lvl[it.first]);
        }
    }
}

int id[MAXN + 1];

void dfs1(int nod, int cur) {
    id[nod] = cur;
    for(auto it : g[nod]) {
        if(id[it.first] == 0 && block[it.second] == 0) {
            dfs1(it.first, cur);
        }
    }
}

vector <int> aux[MAXN + 1];
int dst[MAXN + 1];
int q[MAXN + 1];

inline int bfs(int nod, int n) {
    int b = 0, e = 0;
    memset(dst, 0, sizeof(dst));
    q[e++] = nod;
    dst[nod] = 1;
    while(b < e) {
        nod = q[b];
        b++;
        for(auto it : aux[nod]) {
            if(dst[it] == 0) {
                dst[it] = dst[nod] + 1;
                q[e++] = it;
            }
        }
    }
    nod = 1;
    for(int i = 2; i <= n; i++) {
        if(dst[nod] < dst[i]) {
            nod = i;
        }
    }
    return nod;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back({y, i});
        g[y].push_back({x, i});
    }
    dfs(1, 0);
    int cur = 0;
    for(i = 1; i <= n; i++) {
        if(id[i] == 0) {
            dfs1(i, ++cur);
        }
    }
    for(i = 1; i <= n; i++) {
        for(auto it : g[i]) {
            if(id[i] != id[it.first]) {
                aux[id[i]].push_back(id[it.first]);
                aux[id[it.first]].push_back(id[i]);
            }
        }
    }
    int nod = bfs(1, cur);
    cout << dst[bfs(nod, cur)] - 1;
    //cin.close();
   // cout.close();
    return 0;
}