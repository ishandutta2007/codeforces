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
  long long sig=0;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){
    cin >> nx;
    sig+=nx;
  }
  if((sig%n)!=0){cout << "0\n";return 0;}
  sig/=n;
  long long pl=0,mi=0,ev=0;
  map<long long,int> mp,mm;
  for(int i=0;i<n;i++){
    if(a[i]>sig){
      pl++;
      mp[a[i]]++;
    }
    if(a[i]==sig){ev++;}
    if(a[i]<sig){
      mi++;
      mm[a[i]]++;
    }
  }
  if(pl==0){
    cout << "1\n";
    return 0;
  }

  long long res=1,rem;
  rem=pl;
  for(auto &nx : mp){
    res*=calcnCr(rem,nx.second);
    res%=mod;
    rem-=nx.second;
  }
  rem=mi;
  for(auto &nx : mm){
    res*=calcnCr(rem,nx.second);
    res%=mod;
    rem-=nx.second;
  }

  if(pl==1){
    res*=n;res%=mod;
    res*=calcnCr(n-pl,mi);res%=mod;
  }
  else if(mi==1){
    res*=n;res%=mod;
    res*=calcnCr(n-mi,pl);res%=mod;
  }
  else{
    res*=calcnCr(n,ev);res%=mod;
    res*=2;res%=mod;
  }
  cout << res << '\n';
  return 0;
}