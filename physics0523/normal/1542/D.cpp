#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> q;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    if(s[0]=='+'){
      long long x;
      cin >> x;
      q.push_back(x);
    }
    else{q.push_back(-1);}
  }
  long long res=0;
  for(int i=0;i<n;i++){
    if(q[i]==-1){continue;}
    vector<long long> dp(512,0);
    dp[0]=1;
    for(int j=0;j<i;j++){
      vector<long long> ndp=dp;
      if(q[j]==-1){
        ndp[0]+=dp[0];ndp[0]%=mod;
        for(int k=1;k<dp.size();k++){
          ndp[k-1]+=dp[k];ndp[k-1]%=mod;
        }
      }
      else{
        int del;
        if(q[i]<q[j]){del=0;}else{del=1;}
        for(int k=0;k<dp.size();k++){
          int pt=min((int)ndp.size()-1,k+del);
          ndp[pt]+=dp[k];
          ndp[pt]%=mod;
        }
      }
      dp.swap(ndp);
    }

    for(int j=i+1;j<n;j++){
      vector<long long> ndp=dp;
      if(q[j]==-1){
        for(int k=1;k<dp.size();k++){
          ndp[k-1]+=dp[k];ndp[k-1]%=mod;
        }
      }
      else{
        int del;
        if(q[i]<=q[j]){del=0;}else{del=1;}
        for(int k=0;k<dp.size();k++){
          int pt=min((int)ndp.size()-1,k+del);
          ndp[pt]+=dp[k];
          ndp[pt]%=mod;
        }
      }
      dp.swap(ndp);
    }
    long long sig=0;
    for(auto &nx : dp){sig+=nx;sig%=mod;}
    res+=sig*q[i];res%=mod;
  }
  cout << res << '\n';
  return 0;
}