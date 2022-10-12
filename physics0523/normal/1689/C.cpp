#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int dp(int v,int pv,Graph &g){
  int res=0;
  vector<int> und;
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    und.push_back(dp(nx,v,g));
  }
  sort(und.begin(),und.end());
  // cout << v << ':';
  // for(auto &nx : und){
  //   cout << nx << ' ';
  // }cout << '\n';
  for(int i=0;i<und.size();i++){
    if(i==und.size()-1){res++;}
    else{res+=und[i];}
  }
  return res+1;
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
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cout << n-dp(0,-1,g) << '\n';
  }
  return 0;
}