#include<bits/stdc++.h>

using namespace std;

long long en(long long x,long long k){
  x++;
  long long res=0;
  long long blk=x/(1ll<<(k+1));
  long long rem=x%(1ll<<(k+1));
  res+=blk*(1ll<<k);
  res+=max(0ll,rem-(1ll<<k));
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
    long long res=1e18;
    for(long long i=0;i<60;i++){
      //cerr << i << ':' << en(l-1,i) << ' ' << en(r,i) << '\n';
      res=min(res,(r-l+1)-(en(r,i)-en(l-1,i)));
    }
    cout << res << '\n';
  }
  return 0;
}