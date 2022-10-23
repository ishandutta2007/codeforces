#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long p1,t1;
  cin >> p1 >> t1;
  long long p2,t2;
  cin >> p2 >> t2;
  long long h,s;
  cin >> h >> s;

  vector<long long> way(5005,4e18);
  vector<long long> end(5005,4e18);

  for(long long i=0;i<5005;i++){
    for(long long j=0;j<5005;j++){
      long long dam,cl;
      dam=min(h,i*(p1-s)+j*(p2-s));
      cl=max(i*t1,j*t2);
      end[dam]=min(end[dam],cl);

      dam=min(h,i*(p1-s)+j*(p2-s)+(p1+p2-s));
      cl=max((i+1)*t1,(j+1)*t2);
      way[dam]=min(way[dam],cl);
    }
  }

  vector<long long> dp(h+1,4e18);
  dp[h]=0;
  for(long long i=h;i>0;i--){
    for(long long j=1;j<5005;j++){
      if(i>j){
        dp[i-j]=min(dp[i-j],dp[i]+way[j]);
      }
      else{
        dp[0]=min(dp[0],dp[i]+way[j]);
        dp[0]=min(dp[0],dp[i]+end[j]);
      }
    }
  }
  cout << dp[0] << "\n";
  return 0;
}