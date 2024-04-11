#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

bool comp(const pl &l,const pl &r){
  return (l.first*r.second==l.second*r.first) ? (l.first>r.first) : (l.first*r.second>l.second*r.first);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  long long res=0;
  vector<pl> vp(n);
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    long long sc=0,hc=0;
    for(auto &nx : s){
      if(nx=='s'){sc++;}
      else{res+=sc;hc++;}
    }
    vp[i].first=sc;
    vp[i].second=hc;
  }
  sort(vp.begin(),vp.end(),comp);
  long long sc=0,hc=0;
  for(auto &nx : vp){
    //cout << nx.first << ' ' << nx.second << '\n';
    res+=(sc*nx.second);
    sc+=nx.first;
    hc+=nx.second;
  }
  cout << res << '\n';
  return 0;
}