#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    long long res=0;
    vector<long long> a(n),dp(n,n);
    for(int i=0;i<n;i++){
      dp[i]=i;
      cin >> a[i];
    }
    for(int i=0;i<n;i++){
      if((i+a[i])<n){dp[i+a[i]]=min(dp[i+a[i]],dp[i]);}
      else{
        long long tg=i+a[i];
        res=max(tg-dp[i],res);
      }
    }
    cout << res << '\n';
  }
  return 0;
}