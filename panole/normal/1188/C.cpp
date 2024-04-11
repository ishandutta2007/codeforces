#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,f[1010][1010],p[1010],ans,la,nw,sum[1010][1010],a[1010],k;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n),ans=0,la=0;
	for (int i=1; i<=n; i++) p[i]=0;
	f[0][0]=sum[0][0]=1;
	for (int i=100000/(k-1); i; i--)
	{
		for (int j=1; j<=n; j++)
		{
			while (a[j]-a[p[j]+1]>=i) p[j]++;
			f[j][0]=0,sum[j][0]=sum[j-1][0];
			for (int l=1; l<=k; l++) 
			{
				f[j][l]=sum[p[j]][l-1];
				sum[j][l]=(sum[j-1][l]+f[j][l]>=mod?sum[j-1][l]+f[j][l]-mod:sum[j-1][l]+f[j][l]);
			}
		}
		nw=sum[n][k];
		ans=(ans+1ll*(nw-la)*i)%mod;
		la=nw;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}