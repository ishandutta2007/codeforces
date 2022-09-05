#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a[2001],b[2001],m,f[2001],g[2001],sa[2001],sb[2001];
long long x;

int read()
{
	int p=0,f=1; char c=getchar();
	while (c>'9'||c<'0') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p*f;
}

int main()
{
	scanf("%d%d",&n,&m);
	sa[0]=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),sa[i]=sa[i-1]+a[i];
	sb[0]=0;
	for (int i=1; i<=m; i++) scanf("%d",&b[i]),sb[i]=sb[i-1]+b[i];
	scanf("%I64d",&x);
	for (int i=1; i<=2000; i++) f[i]=g[i]=(1e9);
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			if (sa[j]-sa[i-1]<=f[j-i+1]) f[j-i+1]=sa[j]-sa[i-1];
	for (int i=1; i<=m; i++)
		for (int j=i; j<=m; j++)
			if (sb[j]-sb[i-1]<=g[j-i+1]) g[j-i+1]=sb[j]-sb[i-1];
	int ans=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (1ll*f[i]*g[j]<=x&&i*j>ans) ans=i*j;
	printf("%d\n",ans); 
	return 0;
}