#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<vector<long long>> d(n,vector<long long>(n,1e9));
    vector<vector<long long>> g(n,vector<long long>(n,1e18));
    for(int i=0;i<n;i++){
      d[i][i]=0;
    }
    for(int i=0;i<m;i++){
      long long u,v,w;
      cin >> u >> v >> w;
      u--;v--;
      d[u][v]=min(d[u][v],1ll);
      d[v][u]=min(d[v][u],1ll);
      g[u][v]=min(g[u][v],w);
      g[v][u]=min(g[v][u],w);
    }
    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
      }
    }
    long long res=1e18;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(g[i][j]<5e17){
          long long len=1e18;
          len=min(len,d[0][i]+d[n-1][j]+1);
          len=min(len,d[0][j]+d[n-1][i]+1);
          for(int k=0;k<n;k++){
            len=min(len,min(d[i][k],d[j][k])+1+d[k][0]+d[k][n-1]+1);
          }
          res=min(res,g[i][j]*len);
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}