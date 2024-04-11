#include<cstdio>
#include<cstring>

long long a[100001],f[100001][2],ans;
int n;

long long abs(long long a) {return a<0?-a:a;}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%I64d",&a[i]);
	for (int i=1; i<n; i++) a[i]=abs(a[i+1]-a[i]);
	f[1][1]=a[1]; f[1][0]=0; ans=-(1e16);
	if (f[1][1]>ans) ans=f[1][1];
	if (f[1][0]>ans) ans=f[1][0];
	for (int i=2; i<n; i++)
	{
		if (f[i-1][1]-a[i]>0) f[i][0]=f[i-1][1]-a[i];
		else f[i][0]=0;
		f[i][1]=f[i-1][0]+a[i];
		if (f[i][1]>ans) ans=f[i][1];
		if (f[i][0]>ans) ans=f[i][0];
	}
	printf("%I64d\n",ans);
	return 0;
}