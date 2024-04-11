#include <stdio.h>
typedef long long LL;

int x,y,k;

void solve(){
	scanf("%d%d%d",&x,&y,&k);
	LL s = 1ll*y*k+k;
	LL t1 = (s-1+x-2)/(x-1);
	LL t2 = k;
	printf("%lld\n",t1+t2);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}