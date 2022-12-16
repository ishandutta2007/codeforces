#include <stdio.h>
#include <algorithm>
#define MN 1000

int n,x[MN+5],y[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	std::sort(x+1,x+1+n);
	std::sort(y+1,y+1+n);
	if(n&1){
		puts("1");
	}else{
		printf("%lld\n",1ll*(x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1));
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}