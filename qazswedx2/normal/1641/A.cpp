#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,x,a[1000005],b[1000005],vis[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),vis[i]=0,b[i]=0;
		sort(a+1,a+n+1);
		int t=0;
		for(int i=1;i<=n;i++)
			if(a[i]==a[i-1]) b[t]++;
			else
			{
				a[++t]=a[i];
				b[t]=1;
			}
		n=t;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!b[i]) continue;
			if(1ll*a[i]*x>a[n]) ans+=b[i];
			else
			{
				int u=lower_bound(a+1,a+n+1,a[i]*x)-a;
				if(a[u]==a[i]*x)
				{
					int nw=min(b[u],b[i]);
					b[u]-=nw;
					b[i]-=nw;
				}
				ans+=b[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}