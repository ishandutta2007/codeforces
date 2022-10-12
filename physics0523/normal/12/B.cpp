#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s,t;
  cin >> s >> t;
  sort(s.begin(),s.end());
  for(int i=0;i<s.size();i++){
    if(s[i]!='0'){
      swap(s[0],s[i]);
      break;
    }
  }
  if(s==t){cout << "OK\n";}
  else{cout << "WRONG_ANSWER\n";}
  return 0;
}