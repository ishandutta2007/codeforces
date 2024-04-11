#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,mod;
  cin >> n >> mod;
  vector<long long> dp(n+5,0);
  vector<long long> rw(n+5,0);
  dp[n]=1;rw[n]=1;

  for(long long i=n-1;i>=1;i--){
    long long st,fi;

    fi=n;st=min(i+1,n);
    //cout << '[' << st << ',' << fi << "]\n";
    dp[i]+=rw[st];dp[i]+=mod;dp[i]-=rw[fi+1];dp[i]%=mod;
    for(long long z=2;;z++){
      st=i*z;fi=min(n,(i+1)*z-1);
      if(st>n){break;}
      //cout << '[' << st << ',' << fi << "]\n";
      dp[i]+=rw[st];dp[i]+=mod;dp[i]-=rw[fi+1];dp[i]%=mod;
    }

    rw[i]=(rw[i+1]+dp[i])%mod;
  }
  cout << dp[1] << '\n';
  return 0;
}