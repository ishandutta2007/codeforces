#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,prime[105]={0,2,3,5,7,11,13,17,19,23,29,31,37},tans[100005],vis[15];
int nans[15],a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=11;j++)
				if(a[i]%prime[j]==0)
				{
					tans[i]=j;
					vis[j]=1;
					break;
				}
		int ct=0;
		for(int i=1;i<=11;i++)
			if(vis[i])
				nans[i]=++ct;
		printf("%d\n",ct);
		for(int i=1;i<=n;i++)
			printf("%d ",nans[tans[i]]);
		printf("\n");
	}
	return 0;
}