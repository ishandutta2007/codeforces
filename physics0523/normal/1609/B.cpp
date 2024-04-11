#include<bits/stdc++.h>

using namespace std;

int around(int p,string &s){
  int res=0;
  for(int i=max(0,p-2);i<=p;i++){
    if((i+2)>=s.size()){continue;}
    if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){res++;}
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    int res=0;
    for(int i=2;i<n;i++){
      if(s[i-2]=='a' && s[i-1]=='b' && s[i]=='c'){res++;}
    }
    while(q>0){
      q--;
      int tg;
      string nc;
      cin >> tg >> nc;
      tg--;
      res-=around(tg,s);
      s[tg]=nc[0];
      res+=around(tg,s);
      cout << res << '\n';
    }
  return 0;
}