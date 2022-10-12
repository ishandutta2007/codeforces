#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int res=0;
    for(auto &nx : s){
      res=max(nx-'0',res);
    }
    cout << res << '\n';
  }
  return 0;
}