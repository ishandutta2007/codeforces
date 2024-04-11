#include<bits/stdc++.h>

using namespace std;

long long f(long long x){
  long long mi=9,ma=1;
  while(x>0){
    mi=min(mi,x%10);
    ma=max(ma,x%10);
    x/=10;
  }
  return mi*ma;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    for(long long i=2;i<=k;i++){
      long long dlt=f(n);
      if(dlt==0){break;}
      n+=dlt;
    }
    cout << n << '\n';
  }
  return 0;
}