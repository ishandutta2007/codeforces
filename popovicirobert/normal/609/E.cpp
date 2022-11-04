#include <bits/stdc++.h>
#define ll long long
#define MAXN 200000
#define LOG 17

using namespace std;

struct Edge {
    int x, y;
    int w;
    int p;
    bool operator <(const Edge &other) const {
        return w < other.w;
    }
}edge[MAXN + 1];

int sef[MAXN + 1];

int myfind(int x) {
    if(sef[x] == 0)
        return x;
    return sef[x] = myfind(sef[x]);
}

inline void myunion(int x, int y) {
    if(myfind(x) != myfind(y))
        sef[myfind(x)] = myfind(y);
}

vector < pair <int, int> > g[MAXN + 1];
bool viz[MAXN + 1];
int lvl[MAXN + 1];
ll sol[MAXN + 1];

struct Dp {
    int nod;
    int val;
}dp[MAXN + 1][LOG + 1];

void dfs(int nod) {
     for(auto it : g[nod])
        if(lvl[it.first] == 0) {
            lvl[it.first] = lvl[nod] + 1;
            dfs(it.first);
            dp[it.first][0].nod = nod;
            dp[it.first][0].val = it.second;
        }
}

char lg[2 * MAXN + 1];

int rmq[2 * MAXN + 1][LOG + 1];
int first[MAXN + 1];

int sz;

void euler(int nod) {
    sz++;
    first[nod] = sz;
    rmq[sz][0] = nod;
    for(auto it : g[nod])
      if(lvl[it.first] > lvl[nod]) {
          euler(it.first);
          sz++;
          rmq[sz][0] = nod;
      }
}

inline int get_lca(int x, int y) {
    if(first[x] > first[y])
        swap(x, y);
    int p1 = first[x], p2 = first[y];
    int l = lg[p2 - p1 + 1];
    if(lvl[rmq[p1][l]] < lvl[rmq[p2 - (1 << l) + 1][l]])
        return rmq[p1][l];
    return rmq[p2 - (1 << l) + 1][l];
}

inline int solve(int x, int y) {
    int ans = 0;
    for(int p2 = 17; p2 >= 0; p2--)
        if(lvl[dp[x][p2].nod] >= lvl[y]) {
            ans = max(ans, dp[x][p2].val);
            x = dp[x][p2].nod;
        }
    return ans;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, p2;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
      cin >> edge[i].x >> edge[i].y >> edge[i].w;
      edge[i].p = i;
    }
    sort(edge + 1, edge + m + 1);
    ll sum = 0;
    for(i = 1; i <= m; i++)
      if(myfind(edge[i].x) != myfind(edge[i].y)) {
          myunion(edge[i].x, edge[i].y);
          g[edge[i].x].push_back({edge[i].y, edge[i].w});
          g[edge[i].y].push_back({edge[i].x, edge[i].w});
          sum += edge[i].w;
          viz[i] = 1;
      }
    for(i = 1; i <= m; i++)
      if(viz[i] == 1)
          sol[edge[i].p] = sum;
    lvl[1] = 1;
    dfs(1);
    euler(1);
    for(i = 2; i <= sz; i++)
        lg[i] = lg[i >> 1] + 1;
    for(p2 = 1; (1 << p2) <= sz; p2++)
        for(i = 1; i + (1 << p2) <= sz + 1; i++)
           if(lvl[rmq[i][p2 - 1]] < lvl[rmq[i + (1 << (p2 - 1))][p2 - 1]])
              rmq[i][p2] = rmq[i][p2 - 1];
           else
              rmq[i][p2] = rmq[i + (1 << (p2 - 1))][p2 - 1];
    for(p2 = 1; (1 << p2) <= n; p2++)
        for(i = 1; i <= n; i++) {
           dp[i][p2].nod = dp[dp[i][p2 - 1].nod][p2 - 1].nod;
           dp[i][p2].val = max(dp[i][p2 - 1].val, dp[dp[i][p2 - 1].nod][p2 - 1].val);
        }
    for(i = 1; i <= m; i++)
      if(viz[i] == 0) {
          int x = edge[i].x, y = edge[i].y;
          int lca = get_lca(x, y);
          sol[edge[i].p] = sum - max(solve(x, lca), solve(y, lca)) + edge[i].w;
      }
    for(i = 1; i <= m; i++)
      cout << sol[i] << endl;
    //cin.close();
    //cout.close();
    return 0;
}