#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

long long factorial[524288];
long long invfact[524288];

void cfact(){
  long long i;
  factorial[0]=1;
  factorial[1]=1;
  for(i=2;i<524288;i++){
    factorial[i]=factorial[i-1]*i;
    factorial[i]%=mod;
  }
  invfact[524287]=modular_inverse(factorial[524287]);
  for(i=524286;i>=0;i--){
    invfact[i]=invfact[i+1]*(i+1);
    invfact[i]%=mod;
  }
}

long long calcnCr(long long n,long long k){
  if(k<0 || n<k){return 0;}
  return (factorial[n]*((invfact[k]*invfact[n-k])%mod))%mod;
}

int main(){
  cfact();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(10,0);
  for(int i=0;i<10;i++){cin >> a[i];}

  long long all=0;
  for(int tot=1;tot<=n;tot++){
    vector<long long> dp(tot+1,0);
    dp[0]=1;
    for(int d=0;d<10;d++){
      int v=a[d];
      vector<long long> ndp(tot+1,0);
      int subt=0;
      if(d==0){subt=1;}

      for(int i=0;i<=tot;i++){
        if(dp[i]==0){continue;}
        for(int j=v;i+j<=tot;j++){
          ndp[i+j]+=dp[i]*calcnCr(tot-i-subt,j);
          ndp[i+j]%=mod;
        }
      }
      dp=ndp;
    }
    all+=dp[tot];all%=mod;
  }
  cout << all << "\n";
  return 0;
}