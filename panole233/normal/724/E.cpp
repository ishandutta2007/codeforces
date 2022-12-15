#include<cstdio>
#include<cstring>

int n,c;
int a[10010],b[10010];
long long f[10010],ans;

long long min(long long a,long long b) {return a<b?a:b;}

int main()
{
	scanf("%d%d",&n,&c);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) scanf("%d",&b[i]);
	for (int i=1; i<=n; i++)
	{
		f[i]=1000000000000000;
		for (int j=i; j>=1; j--) f[j]=min(f[j-1]+b[i],f[j]+a[i]+1LL*j*c);
		f[0]+=a[i];
	}
	ans=1000000000000000;
	for (int i=0; i<=n; i++) ans=min(ans,f[i]);
	printf("%I64d",ans);
	return 0;
}