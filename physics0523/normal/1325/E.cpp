#include<bits/stdc++.h>
#define MAX_NUM 1000005

using namespace std;
using Graph=vector<vector<int>>;

int shortest_cycle_rooted(int n,int m,int root,vector<int> &u,vector<int> &v){
  Graph g(n);
  for(int i=0;i<m;i++){
    g[u[i]].push_back(i);
    g[v[i]].push_back(i);
  }
  vector<bool> fl(m,true);
  queue<int> q;
  vector<int> d(n,1e9);
  d[root]=0;
  q.push(root);
  while(!q.empty()){
    int od=q.front();q.pop();
    for(auto &nx : g[od]){
      int nv=(u[nx]^v[nx]^od);
      if(d[nv]>5e8){
        fl[nx]=false;
        d[nv]=d[od]+1;
        q.push(nv);
      }
    }
  }
  int res=1e9;
  for(int i=0;i<m;i++){
    if(fl[i]){
      res=min(d[u[i]]+d[v[i]]+1,res);
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<bool> pfl(MAX_NUM,true);
  vector<vector<int>> sqf(MAX_NUM);
  for(int i=2;i<MAX_NUM;i++){
    if(!pfl[i]){continue;}
    for(int j=i;j<MAX_NUM;j+=i){
      if(i!=j){pfl[j]=false;}
      int cnt=0,mem=j;
      while(mem%i==0){
        cnt++;
        mem/=i;
      }
      if(cnt%2){sqf[j].push_back(i);}
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> mem(MAX_NUM);
  vector<bool> ex(MAX_NUM,false);
  set<pair<int,int>> st;

  for(auto &nx : a){
    cin >> nx;
    if(sqf[nx].size()==0){
      cout << "1\n";
      return 0;
    }
    int u,v;
    if(sqf[nx].size()==1){
      u=sqf[nx][0];
      v=1;
    }
    else{
      u=sqf[nx][0];
      v=sqf[nx][1];
    }
    if(u>v){swap(u,v);}
    mem[u].push_back(v);
    mem[v].push_back(u);
    st.insert({u,v});
    ex[u]=true;
    ex[v]=true;
  }

  if(st.size()!=n){
    cout << "2\n";
    return 0;
  }

  int id=1;
  map<int,int> mp;
  for(int i=1;i<=MAX_NUM;i++){
    if(ex[i]){
      mp[i]=id;
      id++;
    }
  }
  vector<int> gu,gv;
  for(int i=1;i<=MAX_NUM;i++){
    for(auto &nx : mem[i]){
      if(i<nx){
        gu.push_back(mp[i]);
        gv.push_back(mp[nx]);
      }
    }
  }

  int res=1e9;
  for(int i=1;i*i<=MAX_NUM;i++){
    if(mp[i]>0){
      res=min(res,shortest_cycle_rooted(id,gu.size(),mp[i],gu,gv));
    }
  }
  if(res>5e8){res=-1;}
  cout << res << '\n';
  return 0;
}