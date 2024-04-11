#include<bits/stdc++.h>
#define inf 1072114514
#define mod 998244353

using namespace std;
using pi=vector<pair<int,int>>;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  int d[512][512];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){d[i][j]=inf;}
    d[i][i]=0;
  }
  Graph g(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
    d[u][v]=1;
    d[v][u]=1;
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j){cout << ' ';}
      long long res=1;
      vector<bool> fl(n);
      vector<int> phv(n,-100);
      for(int k=0;k<n;k++){
        if(d[i][j]==d[i][k]+d[k][j]){
          if(fl[d[i][k]]){res=0;break;}
          fl[d[i][k]]=true;
          phv[k]=0;
        }
        else{
          int ph=d[i][k]+d[k][j]-d[i][j];
          if(ph<0 || ph%2!=0){res=0;break;}
          ph/=2;
          phv[k]=ph;
        }
      }
      for(int k=0;k<=d[i][j];k++){if(!fl[k]){res=0;break;}}
      for(int k=0;k<n;k++){
        if(phv[k]>0){
          long long ce=0;
          for(auto &nx : g[k]){
            if(phv[nx]+1==phv[k]){ce++;}
          }
          res*=ce;res%=mod;
        }
      }
      cout << res;
    }cout << '\n';
  }
  return 0;
}