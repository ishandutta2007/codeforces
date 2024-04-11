#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[100005],vis[100005],t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			vis[a[i]]++;
		}
		int ct=0;
		for(int i=1;i<=n;i++)
			if(vis[i]) ct++;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(ct>=m) break;
			vis[i]=1;
			ct++;
		}
		if(ct>m)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",n*ct);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(vis[j])
					printf("%d ",j);
		printf("\n");
	}
	return 0;
}