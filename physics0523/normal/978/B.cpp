#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int l;
  string s;
  cin >> l >> s;
  int res=0,c=0;
  for(int i=0;i<l;i++){
    if(s[i]=='x'){
      c++;
      if(c>=3){res++;}
    }
    else{
      c=0;
    }
  }
  cout << res << '\n';
  return 0;
}