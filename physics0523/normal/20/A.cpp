#include<bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  int fl=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='/' && s[i+1]=='/'){continue;}
    if(s[i] == '/' && i==s.size()-1 && fl==1){continue;}
    cout << s[i];
    fl=1;
  }
  cout << '\n';
  return 0;
}