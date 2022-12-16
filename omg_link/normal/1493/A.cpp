#include <stdio.h>

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",n-(k+1)/2);
	for(int i=(k+1)/2;i<k;i++)
		printf("%d ",i);
	for(int i=k+1;i<=n;i++)
		printf("%d ",i);
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}