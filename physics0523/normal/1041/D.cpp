#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,h;
  cin >> n >> h;
  vector<pi> seg;
  int del=0;
  for(int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    seg.push_back({l+del,r-l});
    del-=(r-l);
  }
  seg.push_back({2.1e9,0});
  int res=0,cur=0;
  int l=0,r=0;
  while(r<n){
    if((seg[r].first-seg[l].first)<h){
      cur+=seg[r].second;
      r++;
    }
    else{
      cur-=seg[l].second;
      l++;
    }
    res=max(res,cur);
  }
  cout << res+h << '\n';
  return 0;
}