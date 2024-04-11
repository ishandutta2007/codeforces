#include<bits/stdc++.h>
#define mod 998244353

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
  int n,k;
  cin >> n >> k;
  vector<pair<int,int>> ev;
  for(int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    ev.push_back(make_pair(l,1));
    ev.push_back(make_pair(r+1,-1));
  }
  sort(ev.begin(),ev.end());
  
  long long res=0,cnt=0;
  for(int i=0;i<2*n;i++){
    if(ev[i].second==1){
      if(cnt>=(k-1)){
        res+=calcnCr(cnt,k-1);
        res%=mod;
      }
      cnt++;
    }
    else{
      cnt--;
    }
  }
  cout << res << '\n';
  return 0;
}