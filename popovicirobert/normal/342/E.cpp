#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 1e5;
const int LOG = (int) 17;
const int INF = (int) (1 << 20);

set <int> g[MAXN + 1];
int dp[MAXN + 1][LOG + 1];
int lvl[MAXN + 1];
int sz[MAXN + 1];

void dfs(int nod) {
    for(auto it : g[nod])
       if(lvl[it] == 0) {
           lvl[it] = lvl[nod] + 1;
           dp[it][0] = nod;
           dfs(it);
       }
}

inline void prec(int n) {
    lvl[1] = 1;
    dfs(1);
    for(int p2 = 1; (1 << p2) <= n; p2++)
        for(int i = 1; i <= n; i++)
            dp[i][p2] = dp[dp[i][p2 - 1]][p2 - 1];
}

inline int get_lca(int x, int y) {
     if(lvl[x] < lvl[y])
        swap(x, y);
     int i;
     for(i = LOG; i >= 0; i--)
        if(lvl[dp[x][i]] >= lvl[y])
           x = dp[x][i];
     if(x == y)
        return x;
     for(i = LOG; i >= 0; i--)
        if(dp[x][i] != dp[y][i]) {
           x = dp[x][i];
           y = dp[y][i];
        }
    return dp[x][0];
}

inline int get_dist(int x, int y) {
     return lvl[x] + lvl[y] - 2 * lvl[get_lca(x, y)];
}

int from[MAXN + 1];

void dfs1(int nod, int p) {
    sz[nod] = 1;
    for(auto it : g[nod])
       if(it != p) {
            dfs1(it, nod);
            sz[nod] += sz[it];
       }
}

inline int get_centroid(int nod, int p, int n) {
    for(auto it : g[nod])
        if(it != p && sz[it] > n / 2)
            return get_centroid(it, nod, n);
    return nod;
}

inline void make_tree(int nod, int p) {
    dfs1(nod, 0);
    int centroid = get_centroid(nod, 0, sz[nod]);
    from[centroid] = p;
    for(auto it : g[centroid])
       if(it != p) {
           g[it].erase(centroid);
           make_tree(it, centroid);
       }
    g[centroid].clear();
}

int best[MAXN + 1];

inline void update(int nod) {
    int x = nod;
    while(x > 0) {
        best[x] = min(best[x], get_dist(x, nod));
        x = from[x];
    }
}

inline int query(int nod) {
    int x = nod;
    int ans = INF;
    while(x > 0) {
        ans = min(ans, best[x] + get_dist(x, nod));
        x = from[x];
    }
    return ans;
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, a, b, t, nod;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    prec(n);
    make_tree(1, 0);
    for(i = 1; i <= n; i++)
        best[i] = INF;
    update(1);
    while(m > 0) {
        m--;
        cin >> t >> nod;
        if(t == 1)
            update(nod);
        else
            cout << query(nod) << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}