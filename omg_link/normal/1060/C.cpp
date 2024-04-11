#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 2000
typedef long long LL;
int n,m,x,ans;
int a[MN+5],b[MN+5],f[MN+5][MN+5];
LL pa[MN+5],pb[MN+5],ba[MN+5],bb[MN+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),pa[i]=pa[i-1]+a[i];
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),pb[i]=pb[i-1]+b[i];
	scanf("%d",&x);
	memset(ba,0x7f,sizeof(ba)); memset(bb,0x7f,sizeof(bb));
	for(int i=1;i<=n;i++)
		for(int j=1;i+j-1<=n;j++)
			ba[i]=std::min(ba[i],pa[i+j-1]-pa[j-1]);
	for(int i=1;i<=m;i++)
		for(int j=1;i+j-1<=m;j++)
			bb[i]=std::min(bb[i],pb[i+j-1]-pb[j-1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ba[i]*bb[j]<=x) ans=std::max(ans,i*j);
	printf("%d",ans);
}