#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<pi> g(10);
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if((i+j)<10){g[(i+j)%10].first++;}
      else{g[(i+j)%10].second++;}
    }
  }
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> dp(4,0);
    dp[0]=1;
    while(n>0){
      vector<long long> ndp(4,0);
      for(int i=0;i<4;i++){
        int tg,del;
        if(i&1){del=1;tg=(n+9)%10;}
        else{del=0;tg=n%10;}
        long long ka=0,na=0;
        if((tg+del)<10){na+=g[tg].first;}else{ka+=g[tg].first;}
        ka+=g[tg].second;
        ndp[2+(i/2)]+=ka*dp[i];
        ndp[(i/2)]+=na*dp[i];
      }
      n/=10;
      dp.swap(ndp);
    }
    long long res=dp[0];
    cout << res-2 << '\n';
  }
  return 0;
}