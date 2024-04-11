#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;

void decomp(int v,int pv,vector<vector<int>> &rn,vector<vector<int>> &cs,vector<vector<int>> &g){
  if(pv!=-1){cs[v].push_back(pv);}
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    rn[v].push_back(nx);
    decomp(nx,v,rn,cs,g);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> dp(n+1,0);
    vector<int> cspt;
    for(int i=0;i<m;i++){
      int v;
      cin >> v;
      dp[v]=1;
      cspt.push_back(v);
    }
    vector<vector<int>> g(n+1);
    for(int i=1;i<n;i++){
      int u,v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<vector<int>> rn(n+1),cs(n+1);
    decomp(1,-1,rn,cs,g);
    int res=0;
    vector<int> rnpt={1};
    while(!rnpt.empty()){
      vector<int> nrn;
      for(auto &nx : rnpt){
        if(rn[nx].empty()){res=-1;break;}
        for(auto &ny : rn[nx]){
          if(dp[ny]==1){res++;}
          else{nrn.push_back(ny);}
        }
      }
      if(res==-1){break;}
      rnpt.swap(nrn);
      vector<int> ncs;
      for(auto &nx : cspt){
        if(!cs[nx].empty() && dp[cs[nx][0]]==0){
          dp[cs[nx][0]]=1;
          ncs.push_back(cs[nx][0]);
        }
      }
      cspt.swap(ncs);
      nrn.clear();
      for(auto &nx : rnpt){
        if(dp[nx]==1){res++;}
        else{nrn.push_back(nx);}
      }
      rnpt.swap(nrn);
    }
    if(res==-1){cout << "YES\n";}else{cout << "NO\n";}
    //cout << res << '\n';
  }
  return 0;
}