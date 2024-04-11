#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n),c(n);
  long long res=0;
  vector<pl> pts;
  for(int i=0;i<n;i++){
    cin >> a[i] >> c[i];
    pts.push_back(make_pair(a[i],1ll));
    pts.push_back(make_pair(a[i]+c[i],-1ll));
    res+=c[i];
  }
  int ps=pts.size();
  sort(pts.begin(),pts.end());
  long long dp=0;
  for(int i=0;i<ps;i++){
    dp+=pts[i].second;
    if(i!=(ps-1) && dp==0){res+=pts[i+1].first-pts[i].first;}
  }
  cout << res << '\n';
  return 0;
}