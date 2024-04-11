#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

#define MAXN 111111

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> div(MAXN);
  for(int i=1;i<MAXN;i++){
    for(int j=2*i;j<MAXN;j+=i){div[j].push_back(i);}
  }
  int m;
  cin >> m;
  long long res=1;
  vector<long long> prob(m+1,modular_inverse(m));

  vector<int> mp(m+1);
  vector<int> dp(m+1);
  for(int i=m;i>1;i--){
    long long stab=(m/i);
    long long minv=modular_inverse(m-stab);
    long long exh=(m*minv)%mod;
    res+=prob[i]*exh;res%=mod;
    // cout << i << ':' << prob[i] << ' ' << exh << '\n';

    reverse(div[i].begin(),div[i].end());
    int sz=div[i].size();
    for(int j=0;j<sz;j++){
      mp[div[i][j]]=j;
      dp[div[i][j]]=stab;
    }
    for(auto &nx : div[i]){
      int cur=(m/nx)-dp[nx];
      // cout << i << "->" << nx << ':' << cur << '\n';
      prob[nx]+=(((prob[i]*minv)%mod)*(long long)cur);
      prob[nx]%=mod;
      for(auto &ny : div[nx]){dp[ny]+=cur;}
    }
  }
  cout << res%mod << '\n';
  return 0;
}