#include <stdio.h>
#include <algorithm>
#define MN 100000
typedef long long LL;
int n,l[MN+5],r[MN+5];
LL ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	std::sort(l+1,l+1+n); std::sort(r+1,r+1+n);
	for(int i=1;i<=n;i++) ans+=std::max(l[i],r[i]);
	printf("%lld",ans+n);
}