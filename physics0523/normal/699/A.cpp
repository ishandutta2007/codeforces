#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  int res=2e9;
  for(int i=1;i<n;i++){
    if(s[i-1]=='R' && s[i]=='L'){
      res=min(res,(a[i]-a[i-1])/2);
    }
  }
  if(res>1.5e9){res=-1;}
  cout << res << '\n';
  return 0;
}