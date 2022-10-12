#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using pip=pair<int,pi>;

map<int,set<pip>> g;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> res(n);
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    for(int j=0;j<(m/2);j++){
      int u,v;
      cin >> u >> v;
      mp[u]++;mp[v]++;
      g[u].insert({v,{i,2*j}});
      g[v].insert({u,{i,2*j+1}});
      res[i].push_back('-');res[i].push_back('-');
    }
  }
  vector<int> mem;
  for(auto &nx : mp){
    mem.push_back(nx.first);
    if(nx.second%2){cout << "NO\n";return 0;}
  }
  for(auto &nx : mem){
    while(!g[nx].empty()){
      int p=nx;
      while(1){
        if(g[p].empty()){break;}
        auto it=g[p].begin();
        pip ce=(*it);
        int np=ce.first;
        res[ce.second.first][ce.second.second]='L';
        res[ce.second.first][ce.second.second^1]='R';
        g[np].erase({p,{ce.second.first,ce.second.second^1}});
        g[p].erase(it);
        p=np;
      }
    }
  }
  cout << "YES\n";
  for(int i=0;i<n;i++){cout << res[i] << '\n';}
  return 0;
}