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

vector<long long> pfact(long long x){
  vector<long long> res;
  for(long long i=2;i*i<=x;i++){
    if(x%i==0){
      res.push_back(i);
      while(x%i==0){x/=i;}
    }
  }
  if(x>1){res.push_back(x);}
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x,n;
  cin >> x >> n;
  long long res=1;
  vector<long long> pf=pfact(x);
  for(auto &nx : pf){
    long long cnt=0,rem=(n/nx);
    while(rem>0){
      cnt+=rem;cnt%=(mod-1);
      rem/=nx;
    }
    res*=power(nx,cnt);
    res%=mod;
  }
  cout << res << '\n';
  return 0;
}