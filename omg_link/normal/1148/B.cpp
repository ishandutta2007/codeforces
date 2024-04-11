#include <stdio.h>
#include <algorithm>
#define MN 200000
typedef long long LL;
int n,m,k;
LL ta,tb,a[MN+5],b[MN+5],ans=0;
int main(){
	scanf("%d%d%lld%lld%d",&n,&m,&ta,&tb,&k);
	if(k>=n||k>=m) return 0*puts("-1");
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=ta;
	}
	for(int i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	for(int i=1,j=1;i<=k+1&&i<=n;i++){
		while(j<=m&&b[j]<a[i]) j++;
		if(i+m-j<=k) return 0*puts("-1");
		ans=std::max(ans,b[j+k+1-i]);
	}
	printf("%lld\n",ans+tb);
}