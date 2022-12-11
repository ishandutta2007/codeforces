/* B. I.O.U */

#include <stdio.h>

#define MX_N 110

int val[MX_N];
int n,m;

int main() {
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) {
		val[i] = 0;
	}
	while(m--) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		val[a] -= c;
		val[b] += c;
	}
	int ans = 0;
	for(i=1;i<=n;i++) {
		if(val[i] >= 0)
			ans += val[i];
	}
	printf("%d\n",ans);
	return 0;
}