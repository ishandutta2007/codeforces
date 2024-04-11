#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  int res=0;
  while(t>0){
    t--;
    string s;
    cin >> s;
    if(s[0]=='T'){res+=4;}
    if(s[0]=='C'){res+=6;}
    if(s[0]=='O'){res+=8;}
    if(s[0]=='D'){res+=12;}
    if(s[0]=='I'){res+=20;}
  }
  cout << res << '\n';
  return 0;
}