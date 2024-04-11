#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    mp[v]++;
  }
  int m;
  cin >> m;
  vector<int> b(m),c(m);
  for(int i=0;i<m;i++){cin >> b[i];}
  for(int i=0;i<m;i++){cin >> c[i];}
  int res=0;
  for(int i=1;i<m;i++){
    if(make_pair(mp[b[res]],mp[c[res]]) < make_pair(mp[b[i]],mp[c[i]])){res=i;}
  }
  cout << res+1 << '\n';
  return 0;
}