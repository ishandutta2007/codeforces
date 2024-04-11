#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
using Graph=vector<vector<int>>;

int n,k;
// dp[v][min distance][hardest constraint]
// [k+1]=[inf]
long long dp[105][105][105]={0};
long long prep[105][105];

void merge(int pv,int cv){
  for(int i=0;i<=(k+1);i++){
    for(int j=0;j<=(k+1);j++){
      prep[i][j]=dp[pv][i][j];
      dp[pv][i][j]=0;
    }
  }
  for(int pm=0;pm<=(k+1);pm++){
    for(int ph=0;ph<=(k+1);ph++){
      for(int cm=0;cm<=(k+1);cm++){
        for(int ch=0;ch<=(k+1);ch++){
          int nm=min(pm,cm+1);
          if(nm>=k+1){nm=k+1;}
          int nh=k+1;
          if(ph!=(k+1) && ph<(cm+1)){nh=min(nh,ph);}
          if(ch!=(k+1) && ch<(pm+1)){nh=min(nh,ch-1);}
          if(nh<=0){continue;}
          dp[pv][nm][nh]+=prep[pm][ph]*dp[cv][cm][ch];
          dp[pv][nm][nh]%=mod;
        }
      }
    }
  }
}

void rep(int v,int pv,Graph &g){
  dp[v][0][k+1]=1;
  dp[v][k+1][k]=1;
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    rep(nx,v,g);
    merge(v,nx);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  Graph g(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  rep(0,-1,g);
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<=(k+1);j++){
  //     for(int p=0;p<=(k+1);p++){
  //       cout << i << " " << j << " " << p << " : ";
  //       cout << dp[i][j][p] << "\n";
  //     }
  //   }
  // }
  long long res=0;
  for(int i=0;i<=(k+1);i++){
    res+=dp[0][i][k+1];
    res%=mod;
  }
  cout << res << "\n";
  return 0;
}