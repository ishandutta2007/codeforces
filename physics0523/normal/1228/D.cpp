#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int com(vector<int> &x,vector<int> &y){
  int p=0,q=0;
  while(p<x.size() && q<y.size()){
    if(x[p]==y[q]){return x[p];}
    if(x[p]<y[q]){p++;}
    else{q++;}
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  Graph g(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for(int i=0;i<n;i++){sort(g[i].begin(),g[i].end());}

  int x=0,y,z;
  vector<int> xv=g[x];
  if(xv.empty()){cout << "-1\n";return 0;}
  y=xv[0];
  vector<int> yv=g[y];
  z=com(xv,yv);
  if(z==-1){cout << "-1\n";return 0;}
  vector<int> zv=g[z];

  vector<int> res(n,0);
  for(int i=0;i<n;i++){
    if(g[i]==xv){res[i]=1;}
    else if(g[i]==yv){res[i]=2;}
    else if(g[i]==zv){res[i]=3;}
    else{cout << "-1\n";return 0;}
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}