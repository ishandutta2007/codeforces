#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  long long m;
  cin >> s >> m;
  sort(s.begin(),s.end());
  int l=s.size();
  vector<bool> ext(l,false);
  for(int i=1;i<l;i++){
    if(s[i-1]==s[i]){ext[i]=true;}
  }

  vector<vector<long long>> dp((1<<l),vector<long long>(m,0));
  dp[0][0]=1;
  for(int i=0;i<(1<<l);i++){
    for(int j=0;j<m;j++){
      if(dp[i][j]==0){continue;}
      for(int k=0;k<l;k++){
        if(i&(1<<k)){continue;}
        if(i==0 && s[k]=='0'){continue;}
        if(ext[k] && (i&(1<<(k-1)))==0){continue;}
        int tg=(j*10+(s[k]-'0'))%m;
        dp[i|(1<<k)][tg]+=dp[i][j];
      }
    }
  }
  // for(int i=0;i<(1<<l);i++){
  //   for(int j=0;j<m;j++){
  //     cout << dp[i][j] << ' ';
  //   }cout << '\n';
  // }

  cout << dp[(1<<l)-1][0] << '\n';
  return 0;
}