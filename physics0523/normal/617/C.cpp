#include<bits/stdc++.h>

using namespace std;
using pll=pair<long long,long long>;

long long dist(pll a,pll b){
  return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

void getpt(pll &x){
  cin >> x.first >> x.second;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  pll s1,s2;
  getpt(s1);
  getpt(s2);
  vector<pll> ds;
  for(int i=0;i<n;i++){
    pll pt;
    getpt(pt);
    ds.push_back(make_pair(dist(pt,s1),dist(pt,s2)));
  }
  sort(ds.begin(),ds.end());
  //for(int i=0;i<n;i++){cout << ds[i].first << ' ' << ds[i].second << '\n';}
  for(int i=n-2;i>=0;i--){
    ds[i].second=max(ds[i+1].second,ds[i].second);
  }
  long long res=min(ds[0].second,ds[n-1].first);
  for(int i=1;i<n;i++){
    res=min(ds[i-1].first+ds[i].second,res);
  }
  cout << res << '\n';
  return 0;
}