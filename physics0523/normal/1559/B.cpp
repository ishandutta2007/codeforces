#include<bits/stdc++.h>

using namespace std;

int f(string s){
  int res=0;
  for(int i=1;i<s.size();i++){
    if(s[i-1]==s[i]){res++;}
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    string s;
    cin >> l >> s;
    string r1=s,r2=s;
    if(r1[0]=='?'){r1[0]='R';}
    if(r2[0]=='?'){r2[0]='B';}
    for(int i=1;i<l;i++){
      if(r1[i]=='?'){r1[i]='R'+'B'-r1[i-1];}
      if(r2[i]=='?'){r2[i]='R'+'B'-r2[i-1];}
    }
    if(f(r1)<f(r2)){cout << r1 << '\n';}
    else{cout << r2 << '\n';}
  }
  return 0;
}