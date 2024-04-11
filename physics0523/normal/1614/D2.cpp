#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

#define mx 20'000'005

long long dp[mx]={0};
int cnt[mx]={0};
int walk[mx]={0};

vector<int> genv(int p,int cnt){
  vector<int> v;
  int e=1;
  for(int i=0;i<cnt;i++){
    e*=p;
    v.push_back(e);
  }
  return v;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i=2;i<mx;i++){
    if(walk[i]==0){
      walk[i]=i;
      if(i<=5000){
        for(int j=i*i;j<mx;j+=i){
          walk[j]=i;
        }
      }
    }
  }

  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    map<int,int> mp;
    while(v>1){
      mp[walk[v]]++;
      v/=walk[v];
    }
    vector<int> add={1};
    for(auto &nx : mp){
      int cur=add.size();
      vector<int> del=genv(nx.first,nx.second);
      for(int j=0;j<cur;j++){
        for(auto &ny : del){
          add.push_back(add[j]*ny);
        }
      }
    }
    for(auto &nx : add){cnt[nx]++;}
  }

  vector<int> mem;
  for(int i=1;i<mx;i++){
    dp[i]=cnt[i];
    dp[i]*=i;
    if(cnt[i]>1 || i==1){
      mem.push_back(i);
    }
  }

  reverse(mem.begin(),mem.end());

  for(auto &i : mem){
    for(int j=2*i;j<mx;j+=i){
      long long del=cnt[i]-cnt[j];
      del*=i;
      dp[i]=max(dp[i],dp[j]+del);
    }
  }

  cout << dp[1] << "\n";
  return 0;
}