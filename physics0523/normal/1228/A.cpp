#include<bits/stdc++.h>

using namespace std;

bool jud(int x){
  string s=to_string(x);
  sort(s.begin(),s.end());
  for(int i=1;i<s.size();i++){
    if(s[i-1]==s[i]){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int l,r;
  cin >> l >> r;
  for(int i=l;i<=r;i++){
    if(jud(i)){cout << i << '\n';return 0;}
  }
  cout << "-1\n";
  return 0;
}