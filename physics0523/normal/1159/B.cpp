#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<pl> pv;
  for(int i=0;i<n;i++){
    cin >> a[i];
    pv.push_back({a[i],i});
  }
  sort(pv.begin(),pv.end());
  long long l=0,r=n-1;
  long long res=8e18;
  for(auto &nx : pv){
    while(a[l]<nx.first){l++;}
    while(a[r]<nx.first){r--;}
    long long d=max(nx.second-l,r-nx.second);
    if(d!=0){res=min(res,nx.first/d);}
  }
  cout << res << '\n';
  return 0;
}