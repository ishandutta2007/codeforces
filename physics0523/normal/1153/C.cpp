#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int l;
  string s;
  cin >> l >> s;
  if(l%2){
    cout << ":(\n";
    return 0;
  }
  int p=0,q=0;
  for(auto &nx : s){
    if(nx=='('){p++;}
    if(nx==')'){q++;}
  }
  if(p>(l/2) && q>(l/2)){
    cout << ":(\n";
    return 0;
  }
  for(auto &nx : s){
    if(nx=='?'){
      if(p<(l/2)){nx='(';p++;}
      else{nx=')';q++;}
    }
  }
  int fl=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='('){fl++;}
    else{fl--;}
    if(i!=s.size()-1){
      if(fl<=0){
        cout << ":(\n";
        return 0;
      }
    }
    else{
      if(fl!=0){
        cout << ":(\n";
        return 0;
      }
    }
  }
  cout << s << '\n';
  return 0;
}