#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pll=pair<long long,long long>;

vector<long long> l,r;
long long llzt(long long a,long long b){return max(a,b)-min(a,b);}

pll rep(int v,int pv,Graph &g){
  pll res={0,0};
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    pll cst=rep(nx,v,g);
    long long del;
    del=max(llzt(l[v],l[nx])+cst.first,llzt(l[v],r[nx])+cst.second);
    res.first+=del;
    del=max(llzt(r[v],l[nx])+cst.first,llzt(r[v],r[nx])+cst.second);
    res.second+=del;
  }
  return res;
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
    l.resize(n);
    r.resize(n);
    Graph g(n);
    for(int i=0;i<n;i++){cin >> l[i] >> r[i];}
    for(int i=0;i<n-1;i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    pll res=rep(0,-1,g);
    cout << max(res.first,res.second) << '\n';
  }
  return 0;
}