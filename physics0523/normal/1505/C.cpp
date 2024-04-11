#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  for(int i=2;i<s.size();i++){
    if((s[0]+s[1]-2*'A')%26 != (s[2]-'A')%26){cout << "NO\n";return 0;}
  }
  cout << "YES\n";
  return 0;
}