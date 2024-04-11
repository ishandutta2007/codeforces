#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s,t;
  cin >> s >> t;
  while(t.size()>1){t.pop_back();}
  string res=s+t;
  string pref;
  for(auto &nx : s){
    pref.push_back(nx);
    res=min(res,pref+t);
  }
  cout << res << "\n";
  return 0;
}