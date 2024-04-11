#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    Graph g(n);
    vector<int> b(n,0);
    for(int i=1;i<n;i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      b[u]++;b[v]++;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> ope;
    for(int i=0;i<n;i++){
      if(b[i]<=1){ope.push_back(i);}
    }
    int remv=n;
    for(int i=0;(i<k && !ope.empty());i++){
      vector<int> nope;
      for(auto &nx : ope){
        remv--;
        for(auto &ny : g[nx]){
          b[ny]--;
          if(b[ny]==1){nope.push_back(ny);}
        }
      }
      ope.swap(nope);
    }
    cout << remv << '\n';
  }
  return 0;
}