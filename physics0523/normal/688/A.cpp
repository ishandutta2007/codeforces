#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  string tg;
  for(int i=0;i<n;i++){tg.push_back('1');}
  int res=0,cur=0;
  for(int i=0;i<m;i++){
    string s;
    cin >> s;
    if(s==tg){cur=0;}
    else{cur++;}
    res=max(res,cur);
  }
  cout << res << '\n';
  return 0;
}