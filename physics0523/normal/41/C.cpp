#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int l=s.size();
  string res;
  res.push_back(s[0]);
  int i=1;
  bool at=true;
  while(i<l){
    if(i+3<l && s[i]=='d' && s[i+1]=='o' && s[i+2]=='t'){
      res.push_back('.');
      i+=3;
    }
    else if(at && i+2<l && s[i]=='a' && s[i+1]=='t'){
      res.push_back('@');
      i+=2;
      at=false;
    }
    else{
      res.push_back(s[i]);
      i++;
    }
  }
  cout << res << '\n';
  return 0;
}