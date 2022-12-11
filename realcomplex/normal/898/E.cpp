#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

bool comp(pair<ll,ll>a,pair<ll,ll>b){
  if(a.fi<b.fi)
    return true;
  else if(b.fi<a.fi)
    return false;
  if(a.fi==b.fi)
    return (a.se>b.se);
}

int main(){
  int n;
  cin >> n;
  pair<ll,ll>al[n];
  ll v1,v2;
  ll k;
  ll l;
  for(int i = 0;i<n;i++){
    cin >> k;
    l = sqrt(k);
    v1 = (l*l);
    v2 = (l+1)*(l+1);
    if(k==0){
      al[i] = mp(0,2);
    }
    else{
      al[i] = mp(min(k-v1,v2-k),(k==v1));
    }
  }
  sort(al,al+n,comp);
  ll ans = 0;
  for(int i = 0;i<n;i++){
    if(i<n/2){
      ans += al[i].first;
    }
    else{
      ans += al[i].second;
    }
  }
  cout << ans << "\n";
  return 0;
}