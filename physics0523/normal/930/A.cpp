#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  Graph g(n+1);
  for(int i=2;i<=n;i++){
    int v;
    cin >> v;
    g[v].push_back(i);
  }
  int res=0;
  vector<int> v={1};
  while(!v.empty()){
    vector<int> nv;
    for(auto &nx : v){
      for(auto &ny : g[nx]){
        nv.push_back(ny);
      }
    }
    if(v.size()%2){res++;}
    v=nv;
  }
  cout << res << "\n";
  return 0;
}