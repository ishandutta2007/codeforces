#include <stdio.h>
typedef long long ll;

void solve(){
	ll n,a,b,ap=1;
	scanf("%lld%lld%lld",&n,&a,&b);
	for(;a!=1&&ap<=n&&(n-ap)%b!=0;ap*=a);
	puts(ap<=n&&(n-ap)%b==0?"Yes":"No");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}