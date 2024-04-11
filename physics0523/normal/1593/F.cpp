#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define base 50

using namespace std;

long long dp[40][40][100];
long long ndp[40][40][100];

void go_next(int l,int r){
  for(int i=0;i<40;i++){
    for(int j=0;j<40;j++){
      for(int k=l;k<=r;k++){
        dp[i][j][k]=ndp[i][j][k];
        ndp[i][j][k]=-1;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    for(int i=0;i<40;i++){
      for(int j=0;j<40;j++){
        for(int k=0;k<100;k++){
          dp[i][j][k]=-1;
          ndp[i][j][k]=-1;
        }
      }
    }
    dp[0][0][base]=0;
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int l=base,r=base;
    for(int i=0;i<n;i++){
      int cd=s[i]-'0';
      for(int j=0;j<a;j++){
        for(int k=0;k<b;k++){
          for(int p=l;p<=r;p++){
            if(dp[j][k][p]==-1){continue;}
            ndp[(10*j+cd)%a][k][p+1]=2*dp[j][k][p];
            ndp[j][(10*k+cd)%b][p-1]=2*dp[j][k][p]+1;
          }
        }
      }
      l--;r++;
      go_next(l,r);
    }
    int md=1e9;
    long long res=-1;
    for(int i=l+1;i<r;i++){
      if(dp[0][0][i]==-1){continue;}
      if(md>abs(base-i)){
        md=abs(base-i);
        res=dp[0][0][i];
      }
    }
    if(res==-1){cout << "-1\n";}
    else{
      for(int i=n-1;i>=0;i--){
        if(res&(1ll<<i)){cout << "B";}
        else{cout << "R";}
      }
      cout << '\n';
    }
  }
  return 0;
}