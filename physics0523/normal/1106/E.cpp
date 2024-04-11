#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> s(k),t(k),d(k);
  vector<long long> w(k);
  vector<pair<pl,int>> pv;
  for(int i=0;i<k;i++){
    cin >> s[i] >> t[i] >> d[i] >> w[i];
    pv.push_back({{-w[i],-d[i]},i});
  }
  sort(pv.begin(),pv.end());
  set<int> st;
  for(int i=1;i<=n;i++){st.insert(i);}
  st.insert(1e9);
  vector<int> tg(n+2,-1);
  //cerr << "ok\n";
  for(auto &nx : pv){
    int id=nx.second;
    while(!st.empty()){
      auto it=st.lower_bound(s[id]);
      //cerr << id << ' ' << (*it) << '\n';
      if(it==st.end() || (*it)<=t[id]){
        tg[(*it)]=id;
        st.erase(it);
      }
      else{break;}
    }
  }
  for(int i=n;i>=1;i--){
    if(tg[i]==-1){tg[i]=tg[i+1];}
  }
  //cerr << "ok\n";
  vector<vector<long long>> dp(n+2,vector<long long>(m+1,8e18));
  dp[1][m]=0;
  long long res=8e18;
  for(int i=1;i<=n+1;i++){
    if(tg[i]==-1){
      for(auto &nx : dp[i]){
        if(nx<7e18){res=min(nx,res);}
      }
    }
    else{
      for(int j=0;j<=m;j++){
        int pen=1;
        if(i<s[tg[i]]){pen=0;}
        if(j>=pen){
          dp[i+1][j-pen]=min(dp[i+1][j-pen],dp[i][j]);
        }
        dp[d[tg[i]]+1][j]=min(dp[d[tg[i]]+1][j],dp[i][j]+w[tg[i]]);
      }
    }
  }
  cout << res << '\n';
  return 0;
}