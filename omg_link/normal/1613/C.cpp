#include <stdio.h>
#define MN 100

using ll = long long;

int n,a[MN+5];

ll check(ll k){
	ll ans = 0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]<=k)
			ans += a[i]-a[i-1];
		else
			ans += k;
	}
	return ans+k;
}

void solve(){
	ll h;
	scanf("%d%lld",&n,&h);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ll l=1,r=1e18;
	while(l<=r){
		ll mid = (l+r)>>1;
		if(check(mid)>=h)
			r = mid-1;
		else
			l = mid+1;
	}
	printf("%lld\n",l);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}