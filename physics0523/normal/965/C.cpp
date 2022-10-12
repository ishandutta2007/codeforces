#include<bits/stdc++.h>

using namespace std;

long long n,k,m,d;
long long f(long long x){
  if(x<=0 || m<x){return -1;}
  double apr=((double)x)*((double)d*(double)k+1.0);
  if(apr<2.0e18 && x*(d*k+1)<=n){return -1;}
  long long res=0;
  long long tim,rem;
  if(((double)x)*((double)k)>2.0e18){tim=0;}
  else{tim=n/(x*k);}
  rem=n-tim*(x*k);
  if(rem<x){rem=0;}else{rem=x;}
  return tim*x+rem;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k >> m >> d;
  long long res=0;
  for(long long i=1;i<=10;i++){res=max(f(i),res);}
  for(long long i=0;i<d;i++){
    long long x;
    x=min(n/(1+i*k),m);
    if(x==0){break;}
    for(long long j=x-5;j<=x+5;j++){res=max(f(j),res);}
  }
  cout << res << '\n';
  return 0;
}