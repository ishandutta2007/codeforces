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

//https://oeis.org/A045883
long long A045883(long long n){
  if(n==1){return 0;}
  long long res=0;
  long long ce=1;
  for(long long i=1;i<=n-1;i++){
    long long del=(i*ce)%mod;
    if((n%2)!=(i%2)){//plus
      res+=del;res%=mod;
    }
    else{//minus
      res+=mod;res-=del;res%=mod;
    }
    ce<<=1;ce%=mod;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  long long oc=0;
  for(int i=0;i<n;i++){
    cin >> s[i];
    for(int j=0;j<m;j++){if(s[i][j]=='o'){oc++;}}
  }

  long long res=0;
  for(int i=0;i<n;i++){
    long long cc=0;
    for(int j=0;j<=m;j++){
      if(j==m || s[i][j]=='*'){
        if(cc>=2){
          res+=A045883(cc)*power(2,oc-cc);
          res%=mod;
        }
        cc=0;
      }
      else{cc++;}
    }
  }

  for(int j=0;j<m;j++){
    long long cc=0;
    for(int i=0;i<=n;i++){
      if(i==n || s[i][j]=='*'){
        if(cc>=2){
          res+=A045883(cc)*power(2,oc-cc);
          res%=mod;
        }
        cc=0;
      }
      else{cc++;}
    }
  }

  cout << res << '\n';
  return 0;
}