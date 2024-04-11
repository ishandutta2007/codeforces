#include <stdio.h>
#include <algorithm>
#define MN 100000
typedef long long LL;
const LL e18=1000000000000000000ll;
int n,q,r[MN+5];
LL a[MN+5],qu[MN+5],ans[MN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	std::sort(a+1,a+1+n);
	a[n+1]=a[n]+e18+1;
	for(int i=1;i<=n;i++)
		a[i]=a[i+1]-a[i];
	std::sort(a+1,a+1+n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		qu[i]=y-x+1; r[i]=i;
	}
	std::sort(r+1,r+1+q,[](int a,int b)->bool{return qu[a]<qu[b];});
	LL bsc=0;
	for(int i=1,j=1;i<=q;i++){
		#define i r[i]
		for(;a[j]<qu[i];j++)
			bsc+=(n-j+1)*(a[j]-a[j-1]);
		ans[i]=bsc+(qu[i]-a[j-1])*(n-j+1);
		#undef i
	}
	for(int i=1;i<=q;i++)
		printf("%lld ",ans[i]);
}