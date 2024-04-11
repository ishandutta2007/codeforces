#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<long long> e(m+1),t(m+1),p(m+1);
    vector<vector<long long>> bk(n);
    for(int i=1;i<=m;i++){
      cin >> e[i] >> t[i] >> p[i];
      e[i]--;
      bk[e[i]].push_back(i);
    }
    long long ct=0;
    vector<long long> res;
    for(int i=0;i<n;i++){
      if(bk[i].empty()){res.clear();break;}
      vector<vector<pi>> dp(bk[i].size()+1,vector<pi>(200,{1e9+7,1e9+7}));
      dp[0][0]={0,-1};
      for(int k=0;k<bk[i].size();k++){
        dp[k+1]=dp[k];
        int nx=bk[i][k];
        for(int j=99;j>=0;j--){
          dp[k+1][j+p[nx]]=min(dp[k+1][j+p[nx]],{dp[k+1][j].first+t[nx],-k});
        }
      }
      long long tg=100;
      for(int j=101;j<=199;j++){
        if(dp[bk[i].size()][j]<dp[bk[i].size()][tg]){tg=j;}
      }
      if(ct+dp[bk[i].size()][tg].first > a[i]){res.clear();break;}
      int arrow=bk[i].size();
      ct+=dp[arrow][tg].first;
      while(tg>0){
        //cerr << tg << ' ' << arrow << ':';
        //cerr << bk[i][-dp[arrow][tg].second]  << '\n';
        res.push_back(bk[i][-dp[arrow][tg].second]);
        int nar=-dp[arrow][tg].second;
        tg-=p[bk[i][-dp[arrow][tg].second]];
        arrow=nar;
      }
    }
    if(res.empty()){cout << -1 << '\n';continue;}
    cout << res.size() << '\n';
    for(int i=0;i<res.size();i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}