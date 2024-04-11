#include<bits/stdc++.h>

using namespace std;

vector<long long> pl={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

vector<long long> pf(long long n){
  vector<long long> res;
  for(long long i=2;i*i<=n;i++){
    while(n%i==0){
      n/=i;
      res.push_back(i);
    }
  }
  if(n>1){res.push_back(n);}
  return res;
}

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y);
    }
    y=(y*y);
    b>>=1;
  }
  return x;
}

long long power_huge(long long a,long long b){
  if(b>=100){return 4e18;}
  double pre;
  pre=pow((double)a,(double)b);
  if(pre>4e18){return 4e18;}
  return power(a,b);
}

long long prod_huge(long long a,long long b){
  double pre=(double)a;
  pre*=(double)b;
  if(pre>4e18){return 4e18;}
  return a*b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> p=pf(n);
  long long sz=p.size();
  vector<long long> prod(1ll<<sz,1);
  for(long long i=1;i<(1ll<<sz);i++){
    for(long long j=0;j<sz;j++){
      if(i&(1ll<<j)){prod[i]*=p[j];}
    }
  }
  vector<long long> dp(1ll<<sz,4e18);
  dp[(1ll<<sz)-1]=1;
  for(auto &nx : pl){
    for(long long i=1;i<(1ll<<sz);i++){
      for(long long j=(1ll<<sz)-1;j>=1;j--){
        j&=i;
        dp[i^j]=min(dp[i^j],prod_huge(dp[i],power_huge(nx,prod[j]-1)));
      }
    }
  }
  cout << dp[0] << "\n";
  return 0;
}