#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  long long n;
  cin >> n;
  vector<long long> cnt(n+1,0);
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j+=i){
      cnt[j]++;
    }
  }
  vector<long long> f(n+1,0);
  long long sig=0;
  for(int i=1;i<=n;i++){
    f[i]=sig;
    f[i]+=cnt[i];f[i]%=mod;
    sig+=f[i];sig%=mod;
  }
  cout << f[n] << '\n';
  return 0;
}