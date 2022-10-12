#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pi> vp;
  for(int i=0;i<(n/2);i++){
    for(int j=(n/2);j<n;j++){
      vp.push_back({i+1,j+1});
    }
  }
  cout << vp.size() << '\n';
  for(auto &nx : vp){
    cout << nx.first << ' ' << nx.second << '\n';
  }
  return 0;
}