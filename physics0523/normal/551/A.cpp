#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int,vector<int>> mp;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    mp[-v].push_back(i);
  }
  vector<int> res(n);
  int standing=1;
  for(auto &nx : mp){
    for(auto &ny : nx.second){
      res[ny]=standing;
    }
    standing+=nx.second.size();
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}