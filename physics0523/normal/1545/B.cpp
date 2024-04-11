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
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    string s;
    cin >> n >> s;
    bool able=false;
    for(int i=1;i<n;i++){
      if(s[i-1]=='1' && s[i]=='1'){able=true;}
    }
    if(!able){cout << "1\n";continue;}
    string cv;
    int ml=0;
    for(int i=0;i<n;i++){
      if(s[i]=='0'){
        ml=0;
        cv.push_back('0');
      }
      else if(s[i]=='1'){
        ml++;
        if(ml%2==0){cv.push_back('1');cv.push_back('1');}
      }
    }
    //cout << cv << '\n';
    int md=0;
    int az=0,bz=0,oc=0;
    for(int i=0;i<cv.size();i++){
      if(cv[i]=='0'){
        if(md==0){az++;}else{bz++;}
      }
      else{
        md=1-md;
        oc++;
      }
    }
    int as=(oc+2)/2,bs=(oc+1)/2;
    //cout << as << ' ' << az << '\n';
    //cout << bs << ' ' << bz << '\n';
    cout << (calcnCr(as+az-1,az)*calcnCr(bs+bz-1,bz))%mod << '\n';
  }
  return 0;
}