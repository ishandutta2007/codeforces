#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
using pi=pair<int,int>;

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

//lagrange interpolation
//O(N^2)
//x[i] != x[j]
//return f(t)
long double lagrange_ld(vector<long double> x, vector<long double> y, long double t){
  long long n=x.size();
  long double res=0;
  for(int i=0;i<n;i++){
    long double v=1;
    for(int j=0;j<n;j++){
      if(i==j){continue;}
      v*=(t-x[j]);
      v/=(x[i]-x[j]);
    }
    v*=y[i];
    res+=v;
  }
  return res;
}

int main(){
  int n,m;
  scanf("%d%d",&n,&m);

  vector<vector<long long>> a(m,vector<long long>(n));
  vector<long long> sig(m,0);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      scanf("%lld",&a[i][j]);
      sig[i]+=a[i][j];
    }
  }

  map<long long, long long> mp;
  for(int i=1;i<m;i++){mp[sig[i]-sig[i-1]]++;}
  long long del;
  int err=-1;
  for(auto &nx : mp){if(nx.second>1){del=nx.first;}}
  for(int i=1;i<m-1;i++){
    if(sig[i]-sig[i-1]!=del && sig[i+1]-sig[i]!=del){err=i;}
  }
  if(err==-1){
    if(sig[1]-sig[0]!=del){err=0;}
    else{err=m-1;}
  }
  long long smt;
  if(err==0){smt=(sig[1]-sig[0])-del;}
  else{smt=del-(sig[err]-sig[err-1]);}
  vector<long double> x,y;
  for(int i=0;x.size()<3;i++){
    if(i==err){continue;}
    long double ad=0;
    for(int j=0;j<n;j++){
      ad+=(a[i][j]*a[i][j]);
    }
    x.push_back(i);
    y.push_back(ad);
  }
  long double hkld=lagrange_ld(x,y,(long double)err);
  long long hkll=(long long)(hkld+0.5);
  for(int i=0;i<n;i++){hkll-=(a[err][i]*a[err][i]);}
  long long spt=(hkll/smt);
  printf("%d %lld\n",err,(smt+spt)/2);
  //cout << smt << ' ' << ssmts << '\n';
  fflush(stdout);
  return 0;
}