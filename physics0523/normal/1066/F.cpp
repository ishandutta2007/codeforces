#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

long long f(long long p,long long q){
  if(p<=q){return p;}
  return (2*p-q);
}

pl inv(long long m,long long v){
  if(v<=m){return {v,m};}
  else{return {m,2*m-v};}
}

long long d(pl a,pl b){
  long long res=abs(a.first-b.first);
  res+=abs(a.second-b.second);
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  map<long long,vector<long long>> mp;
  for(int i=0;i<n;i++){
    long long p,q;
    cin >> p >> q;
    mp[max(p,q)].push_back(f(p,q));
  }
  pl lp={0,0},rp={0,0};
  long long ld=0,rd=0;
  for(auto &nx : mp){
    sort(nx.second.begin(),nx.second.end());
    pl nlp=inv(nx.first,nx.second[0]);
    pl nrp=inv(nx.first,nx.second.back());
    // cout << nlp.first << ' ' << nlp.second << ',';
    // cout << nrp.first << ' ' << nrp.second << '\n';
    long long nld=8e18,nrd=8e18;
    nld=min(nld,ld+d(lp,nrp)+d(nrp,nlp));
    nld=min(nld,rd+d(rp,nrp)+d(nrp,nlp));
    nrd=min(nrd,ld+d(lp,nlp)+d(nlp,nrp));
    nrd=min(nrd,rd+d(rp,nlp)+d(nlp,nrp));
    ld=nld;rd=nrd;
    lp=nlp;rp=nrp;
  }
  cout << min(ld,rd) << '\n';
  return 0;
}