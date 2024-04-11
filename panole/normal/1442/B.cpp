#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,T,k,a[200010],p[200010],f[200010],b[200010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k),f[0]=f[n+1]=n+1;
		for (int i=1; i<=n; i++) f[i]=0;
		for (int i=1; i<=n; i++) scanf("%d",&a[i]),p[a[i]]=i;
		for (int i=1; i<=k; i++) scanf("%d",&b[i]),f[p[b[i]]]=i;
		int ans=1;
		for (int i=1,x; i<=k; i++)
			x=p[b[i]],ans=1ll*ans*((f[x-1]<f[x])+(f[x+1]<f[x]))%mod;
		printf("%d\n",ans);
	}
	return 0;
}