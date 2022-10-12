#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,x;
    cin >> n >> x;
    vector<pl> pv;
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      pv.push_back({v,1});
    }
    for(int i=0;;i++){
      if(pv[i].first%x){break;}
      long long adf=pv[i].first/x;
      long long ads=pv[i].second*x;
      pv.push_back({adf,ads});
    }
    long long res=0;
    for(auto &nx : pv){
      res+=nx.first*nx.second;
    }
    cout << res << '\n';
  }
  return 0;
}