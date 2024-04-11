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
    string a,b;
    cin >> s;
    char c='z';
    for(auto &nx : s){c=min(c,nx);}
    for(auto &nx : s){
      if(c==nx){a.push_back(nx);c='+';}
      else{b.push_back(nx);}
    }
    cout << a << ' ' << b << '\n';
  }
  return 0;
}