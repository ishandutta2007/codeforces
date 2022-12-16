#include <stdio.h>

void solve(){
	int n,m;
	scanf("%d%d%*d%*d",&n,&m);
	printf("%d %d %d %d\n",1,1,n,m);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}