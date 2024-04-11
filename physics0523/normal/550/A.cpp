#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int l=s.size();
  set<int> ab,ba;
  for(int i=0;i<l-1;i++){
    if(s[i]=='A' && s[i+1]=='B'){ab.insert(i);}
    if(s[i]=='B' && s[i+1]=='A'){ba.insert(i);}
  }
  bool fl=false;
  for(auto &nx : ab){
    int bas=ba.size();
    if(ba.find(nx-1)!=ba.end()){bas--;}
    if(ba.find(nx+1)!=ba.end()){bas--;}
    if(bas>0){fl=true;break;}
  }

  if(fl){cout << "YES\n";}
  else{cout << "NO\n";}
  return 0;
}