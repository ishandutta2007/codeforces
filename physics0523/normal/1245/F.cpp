#include<bits/stdc++.h>

using namespace std;

long long solve(long long ar,long long br){
  if(ar<0 || br<0){return 0;}
  vector<long long> dp(4);
  dp[3]=1;
  for(int i=31;i>=0;i--){
    vector<long long> ndp(4);
    int av,bv;
    if(ar&(1ll<<i)){av=1;}else{av=0;}
    if(br&(1ll<<i)){bv=1;}else{bv=0;}
    for(int j=0;j<3;j++){
      int ah=1,bh=1;
      if((j&1)==1 && av==0){ah=-1;}
      if((j&1)==0 && av==1){ah=0;}
      if((j&2)==2 && bv==0){bh=-1;}
      if((j&2)==0 && bv==1){bh=0;}
      for(int k=0;k<4;k++){
        int nx=0;
        if(k&1){
          if(ah==-1){continue;}
          if(ah==1){nx++;}
        }
        if(k&2){
          if(bh==-1){continue;}
          if(bh==1){nx+=2;}
        }
        ndp[nx]+=dp[k];
      }
    }
    dp.swap(ndp);
  }
  return dp[0]+dp[1]+dp[2]+dp[3];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long l,r;
    cin >> l >> r;
    cout << solve(r,r)-2*solve(l-1,r)+solve(l-1,l-1) << '\n';
  }
  return 0;
}