#include <stdio.h>
void solve(){
	int l,r;
	scanf("%d%d",&l,&r);
	printf("%d %d\n",l,l*2);
}
int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}