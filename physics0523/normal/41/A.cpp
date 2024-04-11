#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s,t;
  cin >> s >> t;
  reverse(t.begin(),t.end());
  if(s==t){cout << "YES\n";}
  else{cout << "NO\n";}
  return 0;
}