#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

vector<int> calcsig(int v,Graph &g,int n){
  vector<int> d(n,1e9);
  queue<int> q;
  d[v]=1;
  q.push(v);
  while(!q.empty()){
    int od=q.front();q.pop();
    for(auto &nx : g[od]){
      if(d[nx]>5e8){
        d[nx]=-d[od];
        q.push(nx);
      }
    }
  }
  return d;
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
    vector<int> bk(n);
    Graph g(n);
    for(int i=1;i<n;i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
      bk[u]++;bk[v]++;
    }
    vector<int> sig=calcsig(0,g,n);
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << sig[i]*bk[i];
    }cout << '\n';
  }
  return 0;
}