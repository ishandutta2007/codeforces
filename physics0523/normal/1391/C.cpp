#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  long long pow=1,dec=1;
  for(long long i=2;i<=n;i++){
    pow*=i;pow%=mod;
    dec*=2ll;dec%=mod;
  }
  cout << (mod+pow-dec)%mod << '\n';
  return 0;
}