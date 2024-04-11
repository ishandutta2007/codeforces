#include<bits/stdc++.h>

using namespace std;

int d(string s,string t,int l){
  int res=0;
  for(int i=0;i<l;i++){
    res+=max(s[i],t[i]);
    res-=min(s[i],t[i]);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(auto &nx : s){cin >> nx;}
    int res=1e9;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        res=min(res,d(s[i],s[j],m));
      }
    }
    cout << res << '\n';
  }
  return 0;
}