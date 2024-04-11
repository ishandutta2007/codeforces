#include <stdio.h>
typedef long long ll;

ll uppdiv(ll x,ll y){
	return (x+y-1)/y;
}

void solve(){
	ll n;
	scanf("%lld",&n);
	if(n<=6){
		puts("15");
	}else{
		printf("%lld\n",uppdiv(n,2)*5);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}