#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s,t,res;
  cin >> s >> t;
  int l=s.size(),pt=0;
  for(int i=0;i<l;i++){
    if(s[i]!=t[i]){
      if(pt==0){res.push_back(s[i]);pt=1;}
      else{res.push_back(t[i]);pt=0;}
    }
    else{res.push_back('0');}
  }
  if(pt!=0){cout << "impossible\n";}
  else{cout << res << '\n';}
  return 0;
}