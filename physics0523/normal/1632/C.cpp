#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b;
    cin >> a >> b;
    vector<int> dp(8,1e9);
    dp[0]=0;
    for(int tg=22;tg>=0;tg--){
      int ab=(a&(1<<tg));
      int bb=(b&(1<<tg));
      vector<int> ndp(8,1e9);
      for(int i=0;i<8;i++){
        for(int j=0;j<4;j++){
          int as=(j/2),bs=(j%2);
          int nf=i;
          if((nf&2)==0){
            if(ab!=0 && as==0){continue;}
            if(ab==0 && as!=0){nf|=2;}
          }
          if((nf&1)==0){
            if(bb!=0 && bs==0){continue;}
            if(bb==0 && bs!=0){nf|=1;}
          }
          int del=0;
          if(ab!=0 && as==0){del-=(1<<tg);}
          if(ab==0 && as!=0){del+=(1<<tg);}
          if(bb!=0 && bs==0){del-=(1<<tg);}
          if(bb==0 && bs!=0){del+=(1<<tg);}
          if(j==2){del+=(1<<tg);}
          if(j==1){nf|=4;}
          ndp[nf]=min(ndp[nf],dp[i]+del);
        }
      }
      dp.swap(ndp);
    }
    int res=1e9;
    for(int i=0;i<8;i++){
      if(i>=4){dp[i]++;}
      res=min(res,dp[i]);
    }
    cout << res << '\n';
  }
  return 0;
}