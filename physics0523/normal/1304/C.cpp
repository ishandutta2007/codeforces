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
    long long n,m;
    cin >> n >> m;
    map<long long,pl> mp;
    for(int i=0;i<n;i++){
      long long t,l,h;
      cin >> t >> l >> h;
      if(mp.find(t)==mp.end()){
        mp[t]={l,h};
      }
      else{
        mp[t].first=max(mp[t].first,l);
        mp[t].second=min(mp[t].second,h);
      }
    }

    bool fl=true;
    long long ct=0;
    pl rg={m,m};
    for(auto &nx : mp){
      long long dt=nx.first-ct;
      pl crg=nx.second;
      pl nrg={rg.first-dt,rg.second+dt};
      nrg.first=max(nrg.first,crg.first);
      nrg.second=min(nrg.second,crg.second);
      if(nrg.first>nrg.second){fl=false;break;}
      rg=nrg;
      ct=nx.first;
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}