#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

pi add(pi a,pi b){
  return {a.first+b.first,a.second+b.second};
}

pi comp(pi a,pi b){
  if(a.first>b.first){return a;}
  if(a.first<b.first){return b;}
  if(a.second<b.second){return a;}
  return b;
}

vector<vector<pi>> dp;

void rep(int v,int pv,Graph &g){
  dp[v][0]={0,0};
  dp[v][1]={0,0};
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    rep(nx,v,g);
    pi ud=comp(dp[nx][0],dp[nx][1]);
    dp[v][0]=add(dp[v][0],ud);
    dp[v][1]=add(dp[v][1],dp[nx][0]);
  }
  dp[v][1].first++;
  dp[v][1].second+=g[v].size();
  dp[v][0].second++;
}

void rest(int v,int pv,pi res,vector<int> &w,Graph &g){
  pi zero={0,0};
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    zero=add(zero,comp(dp[nx][0],dp[nx][1]));
  }
  zero.second++;
  if(res==zero){
    w[v]=1;
    for(auto &nx : g[v]){
      if(nx==pv){continue;}
      pi ud=comp(dp[nx][0],dp[nx][1]);
      rest(nx,v,ud,w,g);
    }
  }
  else{
    w[v]=g[v].size();
    for(auto &nx : g[v]){
      if(nx==pv){continue;}
      rest(nx,v,dp[nx][0],w,g);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  Graph g(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if(n==2){
    cout << "2 2\n";
    cout << "1 1\n";
    return 0;
  }
  dp.resize(n);
  for(int i=0;i<n;i++){
    dp[i].resize(2);
  }
  rep(0,-1,g);
  vector<int> w(n);
  pi rp=comp(dp[0][0],dp[0][1]);
  rest(0,-1,rp,w,g);

  cout << rp.first << ' ' << rp.second << '\n';
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << w[i];
  }cout << '\n';

  return 0;
}