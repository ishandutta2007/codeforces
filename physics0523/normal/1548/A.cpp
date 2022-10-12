#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
using Graph=vector<set<int>>;

int jud(int id,set<int> &st){
  auto it=st.begin();
  if(-id==(*it)){return 1;}
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  Graph g(n+1);

  for(int i=1;i<=n;i++){g[i].insert(-i);}

  for(int i=0;i<m;i++){
    int p,q;
    cin >> p >> q;
    g[p].insert(-q);
    g[q].insert(-p);
  }

  int res=0;
  for(int i=1;i<=n;i++){
    res+=jud(i,g[i]);
  }

  int q;
  cin >> q;
  for(int i=0;i<q;i++){
    int t;
    cin >> t;
    if(t==1){
      int u,v;
      cin >> u >> v;
      res-=jud(u,g[u]);
      res-=jud(v,g[v]);
      g[u].insert(-v);
      g[v].insert(-u);
      res+=jud(u,g[u]);
      res+=jud(v,g[v]);
    }
    if(t==2){
      int u,v;
      cin >> u >> v;
      res-=jud(u,g[u]);
      res-=jud(v,g[v]);
      g[u].erase(-v);
      g[v].erase(-u);
      res+=jud(u,g[u]);
      res+=jud(v,g[v]);
    }
    if(t==3){
      cout << res << '\n';
    }
  }
  return 0;
}