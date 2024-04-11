#include <stdio.h>
#include <algorithm>
typedef long long ll;

void solve(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	if(a==b){
		puts("0 0");
	}else{
		ll ans1 = std::abs(a-b);
		ll ans2 = std::min(a%ans1,ans1-a%ans1);
		printf("%lld %lld\n",ans1,ans2);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}