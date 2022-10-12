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
    int nc=0;
    for(auto &nx : s){
      if(nx=='N'){nc++;}
    }
    if(nc==1){cout << "NO\n";}
    else{cout << "YES\n";}
  }
  return 0;
}