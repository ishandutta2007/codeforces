#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 1000000
#define rw(x,y) x=std::min(x,y)
typedef long long LL;

int n;
LL r1,r2,r3,minr,d,a[MN+5];
LL f[MN+5][2];

int main(){
	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	r1 = std::min(r1,r3);
	minr = std::min({r1,r2,r3});
	memset(f,0x7f,sizeof(f));
	f[0][0] = -d;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		// 0 -> 0
		rw(f[i][0],f[i-1][0]+r1*a[i]+r3+d);
		// 1 -> 0
		rw(f[i][0],f[i-1][1]+r1*a[i]+r3+3*d);
		// 0 -> 1
		LL c1 = std::min(r1*a[i]+r1,r2)+minr;
		rw(f[i][1],f[i-1][1]+c1+3*d);
		rw(f[i][1],f[i-1][0]+c1+d);
		// 1 -> 1
		rw(f[i][0],f[i-1][1]+c1+3*d);
	}
	LL tans=0;
	for(int i=1;i<=n-1;i++){
		LL c1 = std::min(r1*a[i]+r1,r2)+minr;
		tans = std::min(f[i-1][0]+d,tans)+c1+2*d;
	}
	{
		LL c1 = std::min(r1*a[n]+r1,r2)+minr;
		tans += std::min(r1*a[n]+r3,c1+2*d);
	}
	printf("%lld\n",std::min({f[n][0],f[n][1]+2*d,tans}));
}