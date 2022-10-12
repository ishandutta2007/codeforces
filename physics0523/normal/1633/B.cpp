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
    int p=0,q=0;
    for(auto &nx : s){
      if(nx=='0'){p++;}else{q++;}
    }
    int res;
    if(p==q){res=max(0,p-1);}
    else{res=min(p,q);}
    cout << res << '\n';
  }
  return 0;
}