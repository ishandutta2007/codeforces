#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<long long>>;
using pl=pair<long long,long long>;

pl rep(long long x,long long v,vector<long long> &s,Graph &g){
  if(g[v].empty()){
    return {x*s[v],(x+1)*s[v]};
  }
  long long sz=g[v].size();

  long long p=x/sz;
  long long q=x%sz;

  long long bas=0;
  vector<pl> vp(sz);
  vector<long long> del(sz);
  for(long long i=0;i<sz;i++){
    vp[i]=rep(p,g[v][i],s,g);
    bas+=vp[i].first;
    del[i]=vp[i].second-vp[i].first;
  }

  sort(del.begin(),del.end());
  reverse(del.begin(),del.end());
  long long fir=bas,sec=bas;
  for(long long i=0;i<q;i++){
    fir+=del[i];
  }
  fir+=x*s[v];

  for(long long i=0;i<=q;i++){
    sec+=del[i];
  }
  sec+=(x+1)*s[v];

  // cerr << v << " : " << fir << " , " << sec << "\n";
  return {fir,sec};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    Graph g(n);
    for(long long i=1;i<n;i++){
      long long u;
      cin >> u;
      u--;
      g[u].push_back(i);
    }
    vector<long long> s(n);
    for(auto &nx : s){cin >> nx;}
    cout << rep(k,0,s,g).first << "\n";
  }
  return 0;
}