#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll I=167167167167167167;
ll Q=1e9+7;

int main() {
  ll N;
  cin>>N;
  vector<ll> p(N);
  for(int i=0;i<N;i++) cin>>p[i];
  sort(p.begin(),p.end());
  ll Z=0;
  for(ll i=0;i<N;i++) Z+=min(N,i+2)*p[i];
  cout<<Z<<endl;
}