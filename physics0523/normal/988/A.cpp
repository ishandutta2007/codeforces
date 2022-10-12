#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  map<int,int> mp;
  for(int i=1;i<=n;i++){
    int v;
    cin >> v;
    mp[v]=i;
  }
  vector<int> mem;
  for(auto &nx : mp){mem.push_back(nx.second);}
  if(mem.size()<m){cout << "NO\n";return 0;}
  cout << "YES\n";
  for(int i=0;i<m;i++){
    if(i){cout << ' ';}
    cout << mem[i];
  }cout << '\n';
  return 0;
}