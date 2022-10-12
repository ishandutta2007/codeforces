#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> dp(25252525,0);
  for(int i=2;i<25252525;i++){
    if(dp[i]){continue;}
    for(int j=i;j<25252525;j+=i){dp[j]++;}
  }

  int t;
  cin >> t;
  while(t>0){
    t--;
    long long c,d,x;
    cin >> c >> d >> x;
    long long g=llgcd(llgcd(c,d),x);
    c/=g;d/=g;x/=g;

    long long res=0;
    for(long long i=1;i*i<=x;i++){
      if(x%i){continue;}
      g=i;
      long long rig=(x/g)+d;
      if(rig%c==0){res+=(1ll<<dp[rig/c]);}
      if(i*i==x){break;}
      g=(x/i);
      rig=(x/g)+d;
      if(rig%c==0){res+=(1ll<<dp[rig/c]);}
    }
    cout << res << '\n';
  }
  return 0;
}