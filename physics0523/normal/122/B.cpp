#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int o4=0,o7=0;
  for(auto &nx : s){
    if(nx=='4'){o4++;}
    if(nx=='7'){o7++;}
  }
  if(o4==0 && o7==0){cout << "-1\n";}
  else if(o4<o7){cout << "7\n";}
  else{cout << "4\n";}
  return 0;
}