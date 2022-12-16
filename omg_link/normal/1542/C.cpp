#include <stdio.h>
typedef long long ll;
const int mod = 1000000007;

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

ll _lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}

void solve(){
	ll n,ans,lcm=1;
	scanf("%lld",&n);
	ans = n%mod;
	for(int i=1;lcm<=n;i++){
		lcm = _lcm(lcm,i);
		ans = (ans+n/lcm)%mod;
	}
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}