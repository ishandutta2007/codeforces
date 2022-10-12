// Is this FST?

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define SQRVAL 320

using namespace std;

long long freq(vector<long long> &a){
  if(a.empty()){return 0;}

  sort(a.begin(),a.end());
  long long res=0,cur=1;
  int n=a.size();
  for(int i=0;i<n;i++){
    if(i==n-1 || a[i]!=a[i+1]){
      res=max(res,cur);
      cur=1;
    }
    else{cur++;}
  }
  return res;
}

bool divisible(long long a,long long b){
  return (abs(a)%abs(b))==0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}

  long long r1=0;
  for(long long i=-SQRVAL;i<=SQRVAL;i++){
    vector<long long> cf;
    for(long long j=0;j<n;j++){
      cf.push_back(a[j]-i*j);
    }
    r1=max(r1,freq(cf));
  }

  long long r2=0;
  for(long long i=0;i<n;i++){
    vector<long long> cf;
    for(long long j=-SQRVAL;j<=SQRVAL;j++){
      if(j==0){continue;}
      long long k=i+j;
      if(!(0<=k && k<n)){continue;}
      long long diff=a[k]-a[i];
      if(divisible(diff,j)){cf.push_back(diff/j);}
    }
    r2=max(r2,freq(cf)+1ll);
  }

  //cout << r1 << ' ' << r2 << '\n';
  long long res=max(r1,r2);
  cout << n-res << '\n';
  return 0;
}