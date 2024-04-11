#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define MAXN 200005

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> pf(MAXN);
  for(int i=2;i<MAXN;i++){
    if(!pf[i].empty()){continue;}
    for(int j=i;j<MAXN;j+=i){
      int cj=j;
      while(cj%i==0){
        pf[j].push_back(i);
        cj/=i;
      }
    }
  }
  int n,q;
  cin >> n >> q;
  map<long long,int> ip_c;
  map<long long,int> pc_t;
  long long res=1;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    for(auto &nx : pf[v]){
      long long ip=(((long long)i)<<32)+nx;
      ip_c[ip]++;
      long long pc=(((long long)nx)<<32)+ip_c[ip];
      pc_t[pc]++;
      if(pc_t[pc]==n){res*=nx;res%=mod;}
    }
  }
  for(int t=0;t<q;t++){
    int i,v;
    cin >> i >> v;
    i--;
    for(auto &nx : pf[v]){
      long long ip=(((long long)i)<<32)+nx;
      ip_c[ip]++;
      long long pc=(((long long)nx)<<32)+ip_c[ip];
      pc_t[pc]++;
      if(pc_t[pc]==n){res*=nx;res%=mod;}
    }
    cout << res << '\n';
  }
  return 0;
}