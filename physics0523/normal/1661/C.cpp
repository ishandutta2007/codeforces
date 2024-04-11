#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

long long f(long long x){
  if(x%3==1){return (x/3)*2+1;}
  if(x%3==2){x++;}
  return (x/3)*2;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    long long res=8e18;
    for(long long ext=0;ext<=50;ext++){
      long long tg=a[n-1]+ext;
      long long one=0,two=0;
      for(auto &nx : a){
        long long dlt=tg-nx;
        one+=(dlt%2);
        two+=(dlt/2);
      }
      res=min(res,max(2*one-1,f(one+2*two)));
    }
    cout << res << '\n';
  }
  return 0;
}