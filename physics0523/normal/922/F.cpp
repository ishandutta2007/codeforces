#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  int cnt=0;
  
  Graph g(n+1);
  for(int i=1;i<=n;i++){
    for(int j=2*i;j<=n;j+=i){
      g[i].push_back(j);
      g[j].push_back(i);
      cnt++;
    }
  }
  if(cnt<k){cout << "No\n";return 0;}
  
  cnt-=k;
  vector<bool> fl(n+1,true);
  vector<pi> pv;
  for(int i=2;i<=n;i++){pv.push_back(make_pair(-g[i].size(),i));}
  sort(pv.begin(),pv.end());
  for(auto &nx : pv){
    int tg=nx.second;
    //cout << tg << ' ' << cnt << '\n';
    int ac=0;
    for(auto &ny : g[tg]){if(fl[ny]){ac++;}}
    if(cnt>=ac){
      cnt-=ac;
      fl[tg]=false;
    }
  }
  cout << "Yes\n";
  cnt=0;
  for(int i=1;i<=n;i++){
    if(fl[i]){cnt++;}
  }
  cout << cnt << '\n';
  for(int i=1;i<=n;i++){
    if(fl[i]){
      if(i!=1){cout << ' ';}
      cout << i;
    }
  }cout << '\n';
  return 0;
}