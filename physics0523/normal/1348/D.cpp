#include<bits/stdc++.h>

using namespace std;

long long f(long long n){
  long long res=(n+1);
  for(long long i=0;i<n;i++){
    res+=((n-i)*(1ll<<i));
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    for(long long d=1;;d++){
      if(n<=f(d)){
        cout << d << '\n';
        n-=(d+1);
        vector<long long> res(d);
        long long sig=1;
        for(long long i=0;i<d;i++){
          long long ce=(d-i);
          res[i]=min((n/ce),sig);
          n-=ce*res[i];
          sig+=res[i];
        }
        for(long long i=0;i<d;i++){
          if(i){cout << ' ';}
          cout << res[i];
        }cout << '\n';
        break;
      }
    }
  }
  return 0;
}