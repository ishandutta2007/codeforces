#include <stdio.h>
#define MN 200000

int a,b,k,p[MN+5][2],c[MN+5][2];

void solve(){
	scanf("%d%d%d",&a,&b,&k);
	for(int i=1;i<=a;i++)
		c[i][0] = 0;
	for(int i=1;i<=b;i++)
		c[i][1] = 0;
	long long ans = 0;
	for(int i=1;i<=k;i++)
		scanf("%d",&p[i][0]);
	for(int i=1;i<=k;i++)
		scanf("%d",&p[i][1]);
	for(int i=1;i<=k;i++){
		ans += i-1-c[p[i][0]][0]-c[p[i][1]][1];
		c[p[i][0]][0]++;
		c[p[i][1]][1]++;
	}
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}