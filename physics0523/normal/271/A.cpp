#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x;
  cin >> x;
  for(int i=x+1;;i++){
    string s=to_string(i);
    sort(s.begin(),s.end());
    bool isok=true;
    for(int j=1;j<s.size();j++){
      if(s[j-1]==s[j]){isok=false;}
    }
    if(isok){cout << i << '\n';return 0;}
  }
  return 0;
}