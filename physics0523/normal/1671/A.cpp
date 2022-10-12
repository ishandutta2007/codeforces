#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int l=s.size();
    s="c"+s+"d";
    bool fl=true;
    for(int i=1;i<=l;i++){
      if(s[i-1]!=s[i] && s[i]!=s[i+1]){fl=false;break;}
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}