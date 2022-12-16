#include <stdio.h>

using ll = long long;

ll count(ll c,ll k){
	auto sum = [](ll l,ll r)->ll{
		return (l+r)*(r-l+1)/2;
	};
	if(c<=k) return sum(1,c);
	else return sum(1,k)+sum(2*k-c,k-1);
}

void solve(){
	ll k,x;
	scanf("%lld%lld",&k,&x);
	ll l=1,r=2*k-1;
	while(l<=r){
		int mid = (l+r)>>1;
		if(count(mid,k)<x)
			l = mid+1;
		else
			r = mid-1;
	}
	if(r<2*k-1&&count(r,k)<x) r++;
	printf("%lld\n",r);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}