#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using ppi=pair<pi,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ppi> vp;
  int h,w;
  cin >> h >> w;
  vp.push_back({{h,w},0});
  for(int i=1;i<=n;i++){
    cin >> h >> w;
    vp.push_back({{h,w},i});
  }
  sort(vp.begin(),vp.end());

  vector<int> dp(vp.size(),-1e9);
  vector<int> prev(vp.size(),-1);
  int tg;
  for(int i=0;i<vp.size();i++){
    if(vp[i].second==0){tg=i;break;}
  }
  dp[tg]=1;
  for(int i=tg+1;i<vp.size();i++){
    tg=-1;
    for(int j=0;j<i;j++){
      if(vp[j].first.first < vp[i].first.first && vp[j].first.second < vp[i].first.second){
        if(dp[j]>0){
          if(tg==-1){tg=j;}
          else if(dp[tg]<dp[j]){tg=j;}
        }
      }
    }
    if(tg!=-1){
      dp[i]=dp[tg]+1;
      prev[i]=tg;
    }
  }
  tg=0;
  for(int i=0;i<vp.size();i++){
    if(dp[tg]<dp[i]){tg=i;}
  }
  cout << dp[tg]-1 << '\n';
  vector<int> rv;
  while(tg!=-1){
    rv.push_back(vp[tg].second);
    tg=prev[tg];
  }
  rv.pop_back();
  reverse(rv.begin(),rv.end());
  for(int i=0;i<rv.size();i++){
    if(i){cout << ' ';}
    cout << rv[i];
  }cout << '\n';
  return 0;
}