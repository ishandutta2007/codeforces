#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    pi mi={2e9,-1},ma={-2e9,-1};
    for(int i=1;i<=n;i++){
      int v;
      cin >> v;
      mi=min(mi,{v,i});
      ma=max(ma,{v,i});
    }
    cout << mi.second << ' ' << ma.second << '\n';
  }
  return 0;
}