#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[105],vis[1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(!vis[a[j]-a[i]]) ans++;
				vis[a[j]-a[i]]=1;
			}
		printf("%d\n",ans);
	}
	return 0;
}