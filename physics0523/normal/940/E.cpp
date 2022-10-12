#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,c;
  cin >> n >> c;
  long long sig=0;
  vector<long long> a(n);
  for(auto &nx : a){
    cin >> nx;
    sig+=nx;
  }
  if(n<c){cout << sig << '\n';return 0;}
  vector<long long> dp(n+1,0);
  multiset<long long> ms;
  for(int i=0;i<(c-1);i++){ms.insert(a[i]);}
  for(int i=0;(i+c-1)<n;i++){
    ms.insert(a[i+c-1]);
    dp[i+c]=max(dp[i]+(*ms.begin()),dp[i+c]);
    dp[i+1]=max(dp[i],dp[i+1]);
    ms.erase(ms.find(a[i]));
  }
  long long subt=0;
  for(auto &nx : dp){subt=max(subt,nx);}
  cout << sig-subt << '\n';
  return 0;
}