#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l,k;
    string s;
    cin >> l >> k >> s;
    int st=0,fi=l-1;
    bool fl=true;
    for(int i=0;i<k;i++){
      if(s[st]!=s[fi]){fl=false;break;}
      st++;fi--;
      if(st>fi){fl=false;break;}
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}