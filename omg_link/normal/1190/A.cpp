#include <stdio.h>
#define MM 100000
typedef long long LL;
LL n,k; int m;
LL p[MM+5];
int ans;
int main(){
	scanf("%lld%d%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld",&p[i]);
		--p[i];
	}
	for(int i=1;i<=m;){
		int pre=i-1;
		LL B=(p[i]-pre)/k;
		for(;(p[i]-pre)/k==B;i++);
		++ans;
	}
	printf("%d\n",ans);
}