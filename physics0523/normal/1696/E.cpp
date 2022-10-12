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

#define MAXN 2000005

long long factorial[MAXN];
long long invfact[MAXN];

void cfact(){
  long long i;
  factorial[0]=1;
  factorial[1]=1;
  for(i=2;i<MAXN;i++){
    factorial[i]=factorial[i-1]*i;
    factorial[i]%=mod;
  }
  invfact[MAXN-1]=modular_inverse(factorial[MAXN-1]);
  for(i=MAXN-2;i>=0;i--){
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
  long long n;
  cin >> n;
  vector<long long> a(n+2,0);
  for(int i=0;i<=n;i++){cin >> a[i];}
  if(a[0]==0){
    cout << "0\n";
    return 0;
  }
  
  long long res=0;
  for(int i=0;i<=n;i++){
    // long long rd=0;
    // for(int j=0;j<a[i];j++){
    //   rd+=calcnCr(i+j,i);rd%=mod;
    // }
    // sum[i=0..k] C(n+i,i) = C(k+n+1,k)
    long long del=0;
    if(a[i]>0){del=calcnCr(i+(a[i]-1)+1,a[i]-1);}

    // cout << rd << ' ' << del << '\n';
    res+=del;res%=mod;
  }

  cout << res << '\n';
  return 0;
}