#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// LCA for cpp
// https://atcoder.jp/contests/abc014/tasks/abc014_4
#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using Graph=vector<vector<int>>;

// Based on:
// https://algo-logic.info/lca/
struct LCA {
    vector<vector<int>> parent;
    vector<int> dist;
    LCA(const Graph &G, int root = 0) { init(G, root); }

    void init(const Graph &G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e != p) dfs(G, e, v, d + 1);
        }
    }

    // return {LCA,dist(u,v)}
    pair<int,int> query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);
        int rd=(dist[u]+dist[v]);

        int K = parent.size();
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        if (u == v) return {u,rd-2*dist[u]};
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return {parent[0][u],rd-2*dist[parent[0][u]]};
    }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> dela(n+1,vector<int>(n+1,0));
  int e=0;
  {
    int v1;
    cin >> v1;
    e+=(v1-1);
    Graph g1(v1);
    for(int i=1;i<v1;i++){
      int c;
      cin >> c;
      c--;
      g1[c].push_back(i);
      g1[i].push_back(c);
    }
    vector<int> a(n);
    for(auto &nx : a){
      cin >> nx;
      nx--;
    }
    LCA tra(g1,0);

    for(int i=0;i<n;i++){
      for(int j=i+1;j<=n;j++){
        if(i==0){dela[i][j]=tra.query(0,a[j-1]).second;}
        else{
          int l=tra.query(a[i-1],a[j-1]).first;
          dela[i][j]=tra.query(l,a[j-1]).second;
        }
      }
    }
  }

  vector<vector<int>> delb(n+1,vector<int>(n+1,0));
  {
    int v2;
    cin >> v2;
    e+=(v2-1);
    Graph g2(v2);
    for(int i=1;i<v2;i++){
      int c;
      cin >> c;
      c--;
      g2[c].push_back(i);
      g2[i].push_back(c);
    }
    vector<int> b(n);
    for(auto &nx : b){
      cin >> nx;
      nx--;
    }
    LCA trb(g2,0);

    for(int i=0;i<n;i++){
      for(int j=i+1;j<=n;j++){
        if(i==0){delb[i][j]=trb.query(0,b[j-1]).second;}
        else{
          int l=trb.query(b[i-1],b[j-1]).first;
          delb[i][j]=trb.query(l,b[j-1]).second;
        }
      }
    }
  }

  // for(int i=0;i<=n;i++){
  //   for(int j=i+1;j<=n;j++){
  //     cout << dela[i][j] << ' ';
  //   }cout << '\n';
  // }
  // for(int i=0;i<=n;i++){
  //   for(int j=i+1;j<=n;j++){
  //     cout << delb[i][j] << ' ';
  //   }cout << '\n';
  // }

  vector<vector<int>> dp(n+1,vector<int>(n+1,2e9));
  dp[0][0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int nx=max(i,j)+1;
      dp[nx][j]=min(dp[nx][j],dp[i][j]+dela[i][nx]);
      dp[i][nx]=min(dp[i][nx],dp[i][j]+delb[j][nx]);
    }
  }
  int res=2e9;
  for(int i=0;i<=n;i++){
    res=min(res,dp[i][n]);
    res=min(res,dp[n][i]);
  }
  cout << e-res << '\n';
  return 0;
}