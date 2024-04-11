#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  int res=0;
  for(auto &nx : s){
    if(nx=='+'){res++;}
    else{res--;}
    res=max(0,res);
  }
  cout << res << '\n';
  return 0;
}