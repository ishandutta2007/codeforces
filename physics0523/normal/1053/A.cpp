#include<bits/stdc++.h>

using namespace std;

vector<long long> pfact(long long x){
  vector<long long> res;
  for(long long i=2;i*i<=x;i++){
    while(x%i==0){
      res.push_back(i);
      x/=i;
    }
  }
  if(x!=1){res.push_back(x);}
  return res;
}

set<long long> dvd(multiset<long long> &ms){
  set<long long> res={1};
  for(auto &nx : ms){
    set<long long> ns=res;
    for(auto &ny : res){ns.insert(nx*ny);}
    res.swap(ns);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m,k;
  cin >> n >> m >> k;
  long long prd=n*m*2;
  if(prd%k){cout << "NO\n";return 0;}
  prd/=k;
  multiset<long long> ms;
  vector<long long> p;
  p=pfact(n);
  for(auto &nx : p){ms.insert(nx);}
  p=pfact(m);
  for(auto &nx : p){ms.insert(nx);}
  ms.insert(2);
  p=pfact(k);
  for(auto &nx : p){ms.erase(ms.find(nx));}
  set<long long> yl=dvd(ms);
  for(auto &nx : yl){
    long long nl=nx;
    long long ml=prd/nl;
    if(nl<=n && ml<=m){
      cout << "YES\n";
      cout << 0 << ' ' << 0 << '\n';
      cout << nl << ' ' << 0 << '\n';
      cout << 0 << ' ' << ml << '\n';
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}