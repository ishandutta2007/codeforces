#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int rx;

pair<int,int> rep(int v,int pv,vector<int> &a,Graph &g){
  pair<int,int> res={0,a[v]};
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    pair<int,int> od=rep(nx,v,a,g);
    res.first+=od.first;
    res.second^=od.second;
  }
  if(res.first%2==0 && res.second==rx){res.first++;}
  else if(res.first%2==1 && res.second==0){res.first++;}
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rx=0;
    for(auto &nx : a){
      cin >> nx;
      rx^=nx;
    }
    Graph g(n);
    for(int i=1;i<n;i++){
      int p,q;
      cin >> p >> q;
      p--;q--;
      g[p].push_back(q);
      g[q].push_back(p);
    }

    if(rx==0){cout << "Yes\n";}
    else{
      if(k==2){cout << "No\n";}
      else{
        pair<int,int> rs=rep(0,-1,a,g);
        if(rs.first>=2){cout << "Yes\n";}else{cout << "No\n";}
      }
    }
  }
  return 0;
}