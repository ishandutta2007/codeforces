#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];
char ch[MAXN + 1];

int weight[MAXN + 1];
bool vis[MAXN + 1];
ll sp[MAXN + 1];

void dfs(int nod, int p) {
    weight[nod] = 1;
    sp[nod] = 0;
    for(auto it : g[nod]) {
        if(it != p && vis[it] == 0) {
            dfs(it, nod);
            weight[nod] += weight[it];
        }
    }
}

int getCentroid(int nod, int p, int sz) {
    for(auto it : g[nod]) {
        if(it != p && weight[it] > sz / 2 && vis[it] == 0)
            return getCentroid(it, nod, sz);
    }
    return nod;
}

ll mp[1 << 20];

void dfs1(int nod, int p, int cnf) {
    cnf ^= (1 << ch[nod]);
    for(auto it : g[nod]) {
        if(vis[it] == 0 && it != p)
            dfs1(it, nod, cnf);
    }
    mp[cnf]++;
}

void dfs2(int nod, int p, int cnf, char sign) {
    cnf ^= (1 << ch[nod]);
    mp[cnf] += sign;
    for(auto it : g[nod]) {
        if(it != p && vis[it] == 0) {
            dfs2(it, nod, cnf, sign);
        }
    }
}

ll sol[MAXN + 1], nr;

void dfs3(int nod, int p, int cnf) {
    cnf ^= (1 << ch[nod]);
    sp[nod] += mp[cnf];
    nr += mp[cnf];
    for(int bit = 0; bit < 20; bit++) {
        int conf = (cnf ^ (1 << bit));
        sp[nod] += mp[conf];
        nr += mp[conf];
    }
    if(__builtin_popcount(cnf) < 2) {
        sp[nod]++;
        nr += 2;
    }
    for(auto it : g[nod]) {
        if(it != p && vis[it] == 0)
            dfs3(it, nod, cnf);
    }
}

void dfs4(int nod, int p) {
    for(auto it : g[nod]) {
        if(it != p && vis[it] == 0) {
            dfs4(it, nod);
            sp[nod] += sp[it];
        }
    }
    sol[nod] += sp[nod];
}

void solve(int nod, int p) {
    dfs(nod, p);
    int sz = weight[nod];
    int centroid = getCentroid(nod, p, sz);
    for(auto it : g[centroid]) {
        if(vis[it] == 0)
            dfs1(it, centroid, 0);
    }
    ll aux = sol[centroid];
    nr = 0;
    for(auto it : g[centroid]) {
        if(vis[it] == 0) {
            dfs2(it, centroid, 0, -1);
            dfs3(it, centroid, (1 << ch[centroid]));
            dfs2(it, centroid, 0, 1);
        }
    }
    dfs4(centroid, 0);
    sol[centroid] = aux + nr / 2;
    vis[centroid] = 1;
    for(auto it : g[centroid]) {
        if(it != p && vis[it] == 0)
            dfs2(it, centroid, 0, -1);
    }
    for(auto it : g[centroid]) {
        if(it != p && vis[it] == 0)
            solve(it, centroid);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i = 1; i <= n; i++) {
        cin >> ch[i];
        ch[i] -= 'a';
    }
    solve(1, 0);
    for(i = 1; i <= n; i++) {
        cout << sol[i] + 1 << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}