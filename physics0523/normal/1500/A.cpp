#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using Graph=vector<vector<pi>>;

bool vld(pi a,pi b){
  if(a.first==b.first){return false;}
  if(a.first==b.second){return false;}
  if(a.second==b.first){return false;}
  if(a.second==b.second){return false;}
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  Graph g(7777777);
  for(int i=0;i<n;i++){cin >> a[i];}

  for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){
      int k=(j+i)%n;
      int val=a[j]+a[k];
      pi cp=make_pair(j,k);
      for(auto &nx : g[val]){
        if(vld(cp,nx)){
          cout << "YES\n";
          cout << cp.first+1 << ' ';
          cout << cp.second+1 << ' ';
          cout << nx.first+1 << ' ';
          cout << nx.second+1 << '\n';
          return 0;
        }
      }
      g[val].push_back(cp);
    }
  }
  cout << "NO\n";
  return 0;
}