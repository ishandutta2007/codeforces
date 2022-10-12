#include<bits/stdc++.h>

using namespace std;

bool isp(string s){
  int st=0,fi=s.size()-1;
  while(st<=fi){
    if(s[st]!=s[fi]){return false;}
    st++;fi--;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    string k1="a"+s,k2=s+"a";
    bool f1=isp(k1),f2=isp(k2);
    if(f1&&f2){cout << "NO\n";}
    else if(f1){cout << "YES\n" << k2 << '\n';}
    else{cout << "YES\n" << k1 << '\n';}
  }
  return 0;
}