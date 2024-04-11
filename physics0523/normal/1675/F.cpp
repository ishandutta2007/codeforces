#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int res=0;
vector<int> fl;
bool rep(int v,int pv,int d,Graph &g){
  if(fl[v]==2){res-=d;}
  bool ufl=false;
  if(fl[v]){ufl=true;}
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    ufl|=rep(nx,v,d+1,g);
  }
  if(ufl && pv!=-1){res+=2;}
  return ufl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;

    fl.resize(n);
    for(int i=0;i<n;i++){fl[i]=0;}

    int x,y;
    cin >> x >> y;
    x--;y--;

    for(int i=0;i<k;i++){
      int v;
      cin >> v;
      v--;
      fl[v]=3;
    }
    fl[x]=1;fl[y]=2;

    Graph g(n);
    for(int i=1;i<n;i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    res=0;
    rep(x,-1,0,g);
    cout << res << '\n';
  }
  return 0;
}