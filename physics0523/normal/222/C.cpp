#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

vector<int> pmem;
vector<int> pfact(int x){
  vector<int> res;
  for(auto &i : pmem){
    if(i*i>x){break;}
    while(x%i==0){
      res.push_back(i);
      x/=i;
    }
  }
  if(x>1){res.push_back(x);}
  return res;
}

#define BIG 1048576

map<int,vector<int>> mp;

int main(){
  vector<bool> fl(5005,false);
  for(int i=2;i<5005;i++){
    if(fl[i]){continue;}
    pmem.push_back(i);
    for(int j=i;j<5005;j+=i){fl[j]=true;}
  }
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    vector<int> pf=pfact(v);
    for(auto &nx : pf){
      mp[nx].push_back(i);
    }
  }
  for(int i=0;i<m;i++){
    int v;
    cin >> v;
    vector<int> pf=pfact(v);
    for(auto &nx : pf){
      if(mp[nx].empty() || mp[nx].back()>=BIG){mp[nx].push_back(BIG+i);}
      else{mp[nx].pop_back();}
    }
  }
  vector<int> ra(n,1),rb(m,1);
  for(auto &nx : mp){
    for(auto &ny : nx.second){
      if(ny>=BIG){rb[ny-BIG]*=nx.first;}
      else{ra[ny]*=nx.first;}
    }
  }
  cout << n << ' ' << m << '\n';
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << ra[i];
  }cout << '\n';
  for(int i=0;i<m;i++){
    if(i){cout << ' ';}
    cout << rb[i];
  }cout << '\n';
  return 0;
}