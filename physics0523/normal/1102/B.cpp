#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  map<int,vector<int>> mp;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    mp[v].push_back(i);
  }
  int al=0;
  for(auto &nx : mp){
    al=max(al,(int)nx.second.size());
  }
  if(k<al){cout << "NO\n";return 0;}
  cout << "YES\n";
  int cv=1;
  vector<int> res(n);
  for(auto &nx : mp){
    for(auto &ny : nx.second){
      res[ny]=cv;
      cv++;
      if(cv==k+1){cv=1;}
    }
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}