#include<cstdio>
#include<algorithm>
using namespace std;
int ans,n,k,a[210];
bool vis[210];
int main()
{
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&a[i]);
		}
		for(ans=0;;)
		{
			for(int i=1;i<=k;i++)
			{
				vis[max(1,a[i]-ans)]=1;
				vis[min(n,a[i]+ans)]=1;
			}
			ans++;
			bool flag=1;
			for(int i=1;i<=n;i++)
			{
				if(!vis[i])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}