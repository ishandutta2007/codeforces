#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}

  Graph g(n);
  vector<int> bk(n,0);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    bk[v]++;
    g[u].push_back(v);
  }

  vector<vector<int>> tg(2);
  for(int i=0;i<n;i++){
    if(bk[i]==0){
      tg[a[i]].push_back(i);
    }
  }

  int num=0;
  for(int l=0;;l++){
    int cur=l%2;
    while(!tg[cur].empty()){
      int od=tg[cur].back();
      tg[cur].pop_back();
      num++;

      for(auto &nx : g[od]){
        bk[nx]--;
        if(bk[nx]==0){
          tg[a[nx]].push_back(nx);
        }
      }
    }

    if(num>=n){
      cout << (l+1)/2 << "\n";
      return 0;
    }
  }
  return 0;
}