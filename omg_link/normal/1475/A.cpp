#include <stdio.h>

void solve(){
	long long n;
	scanf("%lld",&n);
	while(!(n&1)) n>>=1;
	if(n==1) puts("NO");
	else puts("YES");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}