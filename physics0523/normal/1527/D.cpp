#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

// based on:
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

    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);
        int K = parent.size();
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}

using pi=pair<int,int>;

void treeDP(int v,int pv,vector<pi> &dp,Graph &g){
  dp[v]={0,0};
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    treeDP(nx,v,dp,g);
    dp[v].first+=dp[nx].first;
    dp[v].second+=dp[nx].second;
  }
  dp[v].first++;
  if(v==1){dp[v].second++;}
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    Graph g(n);
    for(int i=1;i<n;i++){
      int u,v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    LCA lca(g,0);
    vector<pi> dp(n);
    treeDP(0,-1,dp,g);
    vector<long long> res(n+1,llnCr(n,2));
    res[0]=0;
    long long zc=0;
    for(auto &nx : g[0]){
      res[0]+=llnCr(dp[nx].first,2);
      if(dp[nx].second==0){
        zc+=dp[nx].first;
      }
    }
    dp[0]={zc+1,0};

    int a=0,b=1;
    for(int i=1;i<n;i++){
      long long subt;
      subt=dp[a].first;
      subt*=dp[b].first;
      res[i]-=subt;
      if(i==n-1){break;}
      if(lca.query(b,i+1)==i+1){continue;}
      else if(lca.query(a,i+1)==i+1){continue;}
      else if(lca.query(b,i+1)==b){b=i+1;}
      else if(lca.query(a,i+1)==a){a=i+1;}
      else{break;}
      if(lca.query(a,b)!=0){break;}
    }
    for(int i=n;i>=1;i--){res[i]-=res[i-1];}
    for(int i=0;i<=n;i++){
      if(i){
        cout << ' ';
      }
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}