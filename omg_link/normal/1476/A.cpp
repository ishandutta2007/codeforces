#include <stdio.h>

void solve(){
	long long n,k;
	scanf("%lld%lld",&n,&k);
	printf("%lld\n",((n+k-1)/k*k+n-1)/n);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}