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
    bool ok=true;
    if(s[0]!='Y' && s[0]!='y'){ok=false;}
    if(s[1]!='E' && s[1]!='e'){ok=false;}
    if(s[2]!='S' && s[2]!='s'){ok=false;}
    if(ok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}