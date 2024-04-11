#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tt,n,m,a[200005],nxt[200005][2],tans[200005],t;
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		t=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			a[i]=nxt[i][0]=nxt[i][1]=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(!nxt[u][0]) nxt[u][0]=v;
			else nxt[u][1]=v;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==2) tans[++t]=i;
			else
			{
				if(nxt[i][0]) a[nxt[i][0]]=max(a[nxt[i][0]],a[i]+1);
				if(nxt[i][1]) a[nxt[i][1]]=max(a[nxt[i][1]],a[i]+1);
			}
		}
		printf("%d\n",t);
		for(int i=1;i<=t;i++)
			printf("%d ",tans[i]);
		printf("\n");
	}
	return 0;
}