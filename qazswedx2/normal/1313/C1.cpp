#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1000005],st[1000005],tp,lf[1000005],lg[1000005],tans[1000005];
ll f[1000005],g[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(tp&&a[st[tp]]>a[i]) tp--;
		f[i]=f[st[tp]]+1ll*(i-st[tp])*a[i];
		lf[i]=st[tp];
		st[++tp]=i;
	}
	tp=1;
	st[tp]=n+1;
	g[st[tp]]=0;
	for(int i=n;i>0;i--)
	{
		while(tp&&a[st[tp]]>a[i]) tp--;
		g[i]=g[st[tp]]+1ll*(st[tp]-i)*a[i];
		lg[i]=st[tp];
		st[++tp]=i;
	}
	/*for(int i=1;i<=n;i++)
		printf("%I64d ",f[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%I64d ",g[i]);
	printf("\n");*/
	ll ans=-1;
	int id=0;
	for(int i=1;i<=n;i++)
	{
		if(ans<f[i]+g[i]-a[i])
		{
			ans=f[i]+g[i]-a[i];
			id=i;
		}
	}
	tans[id]=a[id];
	int nw=id;
	while(nw)
	{
		for(int j=nw;j>lf[nw];j--)
			tans[j]=a[nw];
		nw=lf[nw];
	}
	nw=id;
	while(nw)
	{
		for(int j=nw;j<lg[nw];j++)
			tans[j]=a[nw];
		nw=lg[nw];
	}
	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]);
	return 0;
}