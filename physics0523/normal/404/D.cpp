#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int l=s.size();
  if(l==1){
    if(s[0]=='?'){cout << "2\n";}
    else if(s[0]=='*' || s[0]=='0'){cout << "1\n";}
    else{cout << "0\n";}
    return 0;
  }

  // 0,1,2,*
  vector<long long> dp(4,0);
  if(s[0]=='0' || s[0]=='?'){dp[0]=1;}
  if(s[0]=='1' || s[0]=='?'){dp[1]=1;}
  if(s[0]=='*' || s[0]=='?'){dp[3]=1;}

  for(int i=1;i<l;i++){
    vector<long long> ndp(4,0);
    if(s[i]=='0' || s[i]=='?'){
      ndp[0]+=dp[0];
    }
    if(s[i]=='1' || s[i]=='?'){
      ndp[1]+=dp[0];
      ndp[0]+=dp[3];
    }
    if(s[i]=='2' || s[i]=='?'){
      ndp[1]+=dp[3];
    }
    if(s[i]=='*' || s[i]=='?'){
      ndp[3]+=dp[1];
      ndp[3]+=dp[3];
    }

    dp=ndp;
    for(auto &nx : dp){nx=nx%mod;}
  }
  cout << (dp[0]+dp[3])%mod << '\n';
  return 0;
}