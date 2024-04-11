#include <bits/stdc++.h>

#define reep(i, s, n) for( int i = s; i < n; ++i )
#define rep(i, n) reep(i, 0, n)
#define X first
#define Y second

using namespace std;

typedef long long ll;

int main()
{
  int n, m;
  cin>>m;
  string str;
  cin>>str;
  n=str.size();
  vector<ll> sum(n+1);
  rep(i,n) sum[i+1]=sum[i]+str[i]-'0';
  map<ll,ll> mp;
  rep(i,n+1) rep(j,i) ++mp[sum[i]-sum[j]];
  //for(auto p:mp)cout<<"("<<p.X<<","<<p.Y<<")";cout<<endl;
  if(!m){
    cout<<mp[0]*(1ll*n*(n+1)/2-mp[0])*2+mp[0]*mp[0]<<endl;
    return 0;
  }
  ll re=0;
  for(auto p:mp)if(p.X){
    if(m%p.X==0)
      re+=mp[m/p.first]*p.second;
  }
  cout<<re<<endl;
  return 0;
}