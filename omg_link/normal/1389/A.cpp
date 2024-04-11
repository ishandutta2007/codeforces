#include <stdio.h>

void solve(){
	int l,r;
	scanf("%d%d",&l,&r);
	if(r>>1<l) puts("-1 -1");
	else printf("%d %d\n",r>>1,r>>1<<1);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}