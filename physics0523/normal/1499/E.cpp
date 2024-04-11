#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define mod 998244353
#define asz 1024

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s,t;
  cin >> s >> t;
  long long ss=s.size();
  long long ts=t.size();
  long long res=0;

  for(int i=0;i<ss;i++){
    int mb=ss-1;
    for(int j=i+1;j<ss;j++){
      if(s[j-1]==s[j]){mb=j-1;break;}
    }
    res+=mod;
    res-=((ts+1)*(mb-i+1))%mod;
    res%=mod;
  }
  for(int i=0;i<ts;i++){
    int mb=ts-1;
    for(int j=i+1;j<ts;j++){
      if(t[j-1]==t[j]){mb=j-1;break;}
    }
    res+=mod;
    res-=((ss+1)*(mb-i+1))%mod;
    res%=mod;
  }

  int dp[asz][asz][27]={0};
  for(int i=0;i<=ss;i++){
    for(int j=0;j<=ts;j++){
      dp[i][j][26]=1;
      for(int k=0;k<=26;k++){
        int cv=dp[i][j][k];
        if(cv==0){continue;}
        if(i!=ss && k!=(s[i]-'a')){
          //cout << i << ' ' << j << ' ' << k << ':' << cv << '\n';
          res+=cv;res%=mod;
          dp[i+1][j][(s[i]-'a')]+=cv;
          dp[i+1][j][(s[i]-'a')]%=mod;
        }
        if(j!=ts && k!=(t[j]-'a')){
          //cout << i << ' ' << j << ' ' << k << ':' << cv << '\n';
          res+=cv;res%=mod;
          dp[i][j+1][(t[j]-'a')]+=cv;
          dp[i][j+1][(t[j]-'a')]%=mod;
        }
      }
    }
  }
  cout << res << '\n';
  return 0;
}