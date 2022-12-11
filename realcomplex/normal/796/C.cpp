#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main(){
  int n;
  cin >> n;
  pair<int,int> d[n];
  for(int i = 0;i<n;i++){
    cin >> d[i].fi;
    d[i].se=i;
  }
  sort(d,d+n);
  int u,v;
  vector<int>e[n];
  for(int i = 1;i<n;i++){
    cin >> u >> v;
    --u;--v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  int ans = (int)2e9;
  int cur;
  for(int i = 0;i<n;i++){
    set<int>g;
    cur = (int)-2e9;
    for(auto x : e[i])
      g.insert(x);
    for(int j = n-1;j>=0;j--){
      if(d[j].se==i){
        cur = max(cur,d[j].fi);
      }
      else if(g.count(d[j].se)){
        cur = max(cur,d[j].fi+1);
      }
      else{
        cur = max(cur,d[j].fi+2);
        break;
      }
    }
    ans = min(ans,cur);
  } 
  cout << ans << "\n";
  return 0;
}