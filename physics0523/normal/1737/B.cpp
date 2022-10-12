#include<bits/stdc++.h>

using namespace std;

long long sqrt_floor(long long x){
  long long st=0,fi=2e9;
  while(st<=fi){
    long long te=(st+fi)/2;
    if(te*te<=x){st=te+1;}
    else{fi=te-1;}
  }
  return fi;
}

long long f(long long x){
  if(x==0){return 0;}
  long long sq=sqrt_floor(x);
  long long res=3*(sq-1);
  long long fir=sq*sq;
  long long sec=sq*sq+sq;
  long long thi=sq*sq+2*sq;
  if(fir<=x){res++;}
  if(sec<=x){res++;}
  if(thi<=x){res++;}
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long l,r;
    cin >> l >> r;
    cout << f(r)-f(l-1) << "\n";
  }
  return 0;
}