#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

vector<int> emp={};
Graph res;

void rep(int v,int id,Graph &g){
  // cerr << v << ' ' << id << '\n';
  for(int i=0;i<g[v].size();i++){
    if(i){
      int nid=res.size();
      res.push_back(emp);
      res[nid].push_back(g[v][i]);
      rep(g[v][i],nid,g);
    }
    else{
      res[id].push_back(g[v][i]);
      rep(g[v][i],id,g);
    }
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
    Graph g(n);
    int rt=-1;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      v--;
      if(i!=v){g[v].push_back(i);}
      else{rt=i;}
    }
    res.clear();
    res.push_back(emp);
    res[0].push_back(rt);
    rep(rt,0,g);

    cout << res.size() << '\n';
    for(auto &nx : res){
      cout << nx.size() << '\n';
      for(int i=0;i<nx.size();i++){
        if(i){cout << ' ';}
        cout << nx[i]+1;
      }cout << '\n';
    }
  }
  return 0;
}