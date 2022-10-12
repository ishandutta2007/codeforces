#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;
using Graph=vector<vector<int>>;

void rep(int v,int pv,int cid,int cl,vector<pair<int,int>> &info,Graph &g,Graph &mem){
  info[v]=make_pair(cid,cl);
  mem[cid].push_back(v);
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    rep(nx,v,cid,cl+1,info,g,mem);
  }
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<int> a(n+1);
  Graph g(n+1);
  for(int i=1;i<=n;i++){cin >> a[i];}
  vector<int> fl(n+1,0);
  for(int i=0;i<k;i++){
    int p,q;
    cin >> p >> q;
    g[p].push_back(q);
    fl[q]=1;
  }
  vector<pair<int,int>> info(n+1);
  Graph mem(n+1);
  int kt=0;
  for(int i=1;i<=n;i++){
    if(fl[i]==1){continue;}
    kt++;
    rep(i,-1,kt,1,info,g,mem);
  }
  Graph ng(kt+1);
  vector<int> ngc(kt+1);
  for(int i=1;i<=n;i++){
    if(a[i]==0){continue;}
    if(info[i].first==info[a[i]].first){
      if(info[i].second<=info[a[i]].second){cout << "0\n";return 0;}
      continue;
    }
    ngc[info[i].first]++;
    ng[info[a[i]].first].push_back(info[i].first);
  }
  queue<int> qu;
  for(int i=1;i<=kt;i++){
    if(ngc[i]==0){qu.push(i);}
  }
  vector<int> nr;
  while(!qu.empty()){
    int nd=qu.front();
    qu.pop();
    nr.push_back(nd);
    for(auto &nx : ng[nd]){
      ngc[nx]--;
      if(ngc[nx]==0){qu.push(nx);}
    }
  }
  vector<int> res;
  for(auto &v : nr){
    for(auto &w : mem[v]){
      res.push_back(w);
    }
  }
  if(res.size()!=n){cout << "0\n";return 0;}
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << "\n";
  return 0;
}