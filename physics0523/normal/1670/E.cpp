#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using Graph=vector<vector<pi>>;

int p;
vector<int> vert;
vector<int> eg;
int vd;

void rep(int v,int pv,int knd,Graph &g){
  for(auto &nx : g[v]){
    if(nx.first==pv){continue;}
    if(knd==1){
      eg[nx.second]=vd+(1<<p);
      vert[nx.first]=vd;
    }
    else{
      eg[nx.second]=vd;
      vert[nx.first]=vd+(1<<p);
    }
    vd++;
    rep(nx.first,v,1-knd,g);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    cin >> p;
    int n=(1<<p);
    vert.resize(n);
    eg.resize(n-1);
    Graph g(n);
    for(int i=0;i<(n-1);i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back({v,i});
      g[v].push_back({u,i});
    }
    vd=1;
    vert[0]=(1<<p);
    rep(0,-1,1,g);

    cout << "1\n";
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << vert[i];
    }cout << '\n';
    for(int i=0;i<(n-1);i++){
      if(i){cout << ' ';}
      cout << eg[i];
    }cout << '\n';
  }
  return 0;
}