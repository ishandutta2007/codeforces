#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int,int> mp;
  for(int i=1;i<=n;i++){
    int v;
    cin >> v;
    mp[v]=i;
  }
  vector<pi> vp;
  for(auto &nx : mp){
    vp.push_back({nx.second,nx.first});
  }
  sort(vp.begin(),vp.end());
  cout << vp.size() << '\n';
  for(int i=0;i<vp.size();i++){
    if(i){cout << ' ';}
    cout << vp[i].second;
  }cout << '\n';
  return 0;
}