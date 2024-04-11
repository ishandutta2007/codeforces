#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using Graph=vector<vector<pi>>;

vector<int> res;

void rep(int v,int pv,int cw,Graph &g){
  for(auto &nx : g[v]){
    if(nx.first==pv){continue;}
    res[nx.second]=cw;
    rep(nx.first,v,5-cw,g);
  }
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
    res.resize(n-1);
    Graph g(n);
    vector<int> u(n),v(n);
    vector<int> bk(n,0);
    for(int i=0;i<n-1;i++){
      cin >> u[i] >> v[i];
      u[i]--;v[i]--;
      bk[u[i]]++;
      bk[v[i]]++;
      g[u[i]].push_back({v[i],i});
      g[v[i]].push_back({u[i],i});
    }
    bool isok=true;
    for(auto &nx : bk){
      if(nx>=3){isok=false;}
    }
    if(!isok){cout << "-1\n";continue;}
    int leaf=-1;
    for(int i=0;i<n;i++){
      if(bk[i]==1){leaf=i;break;}
    }
    rep(leaf,-1,2,g);
    for(int i=0;i<n-1;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}