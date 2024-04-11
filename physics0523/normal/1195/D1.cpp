#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  long long res=0;
  for(long long i=0;i<n;i++){
    long long f=11;
    while(a[i]>0){
      res+=(a[i]%10)*f;res%=mod;
      a[i]/=10;
      f*=100;f%=mod;
    }
  }
  cout << (res*n)%mod << "\n";
  return 0;
}