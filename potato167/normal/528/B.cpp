#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll I=167167167167167167;
ll Q=1e9+7;

int main() {
  ll N;
  cin>>N;
  vector<pair<ll,ll>> p(N);
  for(int i=0;i<N;i++){
    ll x,w;
    cin>>x>>w;
    p[i]=make_pair(x+w,x-w);
  }
  sort(p.begin(),p.end());
  ll A=I*-1,Z=0;
  for(int i=0;i<N;i++){
    if(A<=p[i].second) A=p[i].first,Z++;
  }
  cout<<Z<<endl;
}