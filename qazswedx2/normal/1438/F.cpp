#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,vis[1000005];
int main()
{
	scanf("%d",&n);
	n=(1<<n)-1;
	for(int i=1;i<=420;i++)
	{
		int u=rand()%n+1,v=rand()%n+1,w=rand()%n+1,x;
		while(u==v||v==w||u==w) u=rand()%n+1,v=rand()%n+1,w=rand()%n+1;
		printf("? %d %d %d\n",u,v,w);
		fflush(stdout);
		scanf("%d",&x);
		vis[x]++;
	}
	int mx=-1,u=0,sd=-1,v=0;
	for(int i=1;i<=n;i++)
	{
		if(mx<vis[i])
		{
			v=u,sd=mx;
			mx=vis[i],u=i;
		}
		else if(sd<vis[i])
		{
			v=i;
			sd=vis[i];
		}
	}
	for(int i=1;i<=n;i++)
		if(i!=u&&i!=v)
		{
			int x;
			printf("? %d %d %d\n",u,v,i);
			fflush(stdout);
			scanf("%d",&x);
			if(x==i)
			{
				printf("! %d\n",i);
				return 0;
			}
		}
	return 0;
}