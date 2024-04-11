#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      mp[v].push_back(i);
    }
    int res=-1;
    for(auto &v : mp){
      int m=v.second.size();
      for(int i=1;i<m;i++){
        int p=v.second[i-1];
        int q=v.second[i];
        res=max(p+(n-q),res);
      }
    }
    cout << res << '\n';
  }
  return 0;
}