#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;

int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  int a[32];
  for(int i=0;i<n;i++){cin >> a[i];}
  int dp[8388608];
  for(int i=0;i<8388608;i++){dp[i]=inf;}
  int res=inf;
  dp[1]=1;
  int ct=1;
  for(int i=1;i<(1<<n);i++){
    if((1<<ct)==i){ct++;}
    if(dp[i]==inf){continue;}
    if(ct==n){res=min(dp[i],res);}
    else{
      int fl=0;
      for(int j=0;j<ct;j++){
        if((i&(1<<j))==0){continue;}
        for(int k=j;k<ct;k++){
          if((i&(1<<k))==0){continue;}
          if(a[j]+a[k]==a[ct]){fl=1;break;}
        }
        if(fl){break;}
      }
      if(fl==0){continue;}
      int cv=dsumb(i,2),bp=(i|(1<<ct));
      dp[bp]=min(cv+1,dp[bp]);
      for(int j=0;j<ct;j++){
        if((bp&(1<<j))){
          dp[bp^(1<<j)]=min(cv,dp[bp^(1<<j)]);
        }
      }
    }
  }
  if(res==inf){cout << "-1\n";}
  else{cout << res << '\n';}
}