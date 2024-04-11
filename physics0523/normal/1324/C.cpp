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
    int res=0,cur=1;
    for(auto &nx : s){
      if(nx=='L'){cur++;}
      else{
        res=max(res,cur);
        cur=1;
      }
    }
    res=max(res,cur);
    cout << res << '\n';
  }
  return 0;
}