#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,res=0;
  string s,t;
  cin >> n >> s >> t;
  for(int i=0;i<n;i++){
    res+=min(abs(s[i]-t[i]),10-abs(s[i]-t[i]));
  }
  cout << res << '\n';
  return 0;
}