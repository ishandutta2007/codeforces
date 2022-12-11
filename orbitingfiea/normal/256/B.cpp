#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;

ll n,x,y,c;

ll cal(ll x,ll y,ll z){
  if (x>y) swap(x,y);
  if (!x) return 0;
  if (z<=x) return z*(z+1)/2;
  if (z<=y) return (z-x)*x+x*(x+1)/2;
  z=max(0ll,x+y-1-z); return x*y-z*(z+1)/2;
}

bool chk(ll now){
  ll t=0;
  t+=cal(x-1,y-1,now-1);
  t+=cal(n-x+1,y,now+1);
  t+=cal(x,n-y+1,now+1);
  t+=cal(n-x,n-y,now-1);
  //cerr<<now<<' '<<t<<endl;
  return t>c;
}

int main(){
  ios::sync_with_stdio(0);
  cin>>n>>x>>y>>c;
  ll l=0,r=n*2,mid,ans=0;
  for (;l<=r;) chk(mid=l+r>>1)? r=(ans=mid)-1: l=mid+1;
  cout<<ans<<endl;
}