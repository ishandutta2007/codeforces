#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,c;
  cin >> n >> c;
  vector<long long> dp(c+1,0);
  for(long long i=0;i<n;i++){
    long long uc,d,h;
    cin >> uc >> d >> h;
    dp[uc]=max(dp[uc],d*h);
  }
  for(long long i=c;i>=1;i--){
    long long v=dp[i];
    for(long long j=1;i*j<=c;j++){
      dp[i*j]=max(dp[i*j],v*j);
    }
  }
  for(long long i=1;i<=c;i++){
    dp[i]=max(dp[i],dp[i-1]);
  }
  long long q;
  cin >> q;
  for(int i=0;i<q;i++){
    if(i){cout << ' ';}
    long long d,h;
    cin >> d >> h;
    long long st=0,fi=c;
    while(st<=fi){
      long long te=(st+fi)/2;
      if(dp[te]>d*h){fi=te-1;}else{st=te+1;}
    }
    if(st>c){st=-1;}
    cout << st;
  }cout << '\n';
  return 0;
}