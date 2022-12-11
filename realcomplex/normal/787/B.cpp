#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int k;
  int sk;
  bool ans = true;//not doomed
  bool cur;
  while(m--){
    cin >> k;
    cur=true;//doomed
    set<int>l;
    for(int i = 0;i<k;i++){
      cin >> sk;
      l.insert(sk);
    }
    for(auto x : l){
      if(l.count(-x))cur=false;// not doomed
    }
    if(cur==true)ans=false;//doomed
  }
  cout << ((ans==true) ? "NO\n" : "YES\n");
  return 0;
}