#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t=1;
  // cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int del=2e9;
    long long res=0;
    for(int i=n-1;i>=0;i--){
      del=max(0,min(del-1,a[i]));
      res+=del;
    }
    cout << res << '\n';
  }
  return 0;
}