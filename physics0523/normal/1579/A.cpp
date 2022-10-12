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
    int a=0,b=0,c=0;
    for(auto &nx : s){
      if(nx=='A'){a++;}
      if(nx=='B'){b++;}
      if(nx=='C'){c++;}
    }
    if(b==a+c){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}