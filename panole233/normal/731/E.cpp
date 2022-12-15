#include <cstdio>

long long f[300001];
int g[300001],h[300001];
int n;
long long s;

long long max(long long a,long long b) {return a>b?a:b;}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&g[i]);
	for (int i=1; i<=n; i++)
		h[i]=h[i-1]+g[i];
	f[n]=h[n]; s=f[n];
	for (int i=n-1; i>1; i--)
		f[i]=h[i]-s,s=max(s,f[i]);
	printf("%I64d",s);
	return 0;
}