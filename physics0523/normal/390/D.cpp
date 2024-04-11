#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<pair<int,pi>> mem;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      mem.push_back({i+j,{i,j}});
    }
  }
  sort(mem.begin(),mem.end());
  vector<pi> vp;
  for(int i=0;i<k;i++){
    vp.push_back(mem[i].second);
  }
  sort(vp.begin(),vp.end());
  reverse(vp.begin(),vp.end());
  int res=0;
  for(auto &nx : vp){
    res+=(nx.first+nx.second)-1;
  }
  cout << res << "\n";
  for(auto &nx : vp){
    int p=1,q=1;
    cout << "(1,1)";
    while(q<nx.second){
      q++;
      cout << " (" << p << "," << q << ")";
    }
    while(p<nx.first){
      p++;
      cout << " (" << p << "," << q << ")";
    }
    cout << "\n";
  }
  return 0;
}