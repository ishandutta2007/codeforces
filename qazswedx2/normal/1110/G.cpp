#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int tt,n,h[500005],deg[500005],t,d[500005],mx,id,cnt[500005];
char s[500005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	if(d[u]>mx)
	{
		mx=d[u];
		id=u;
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		t=0;
		scanf("%d",&n);
		for(int i=0;i<=n+1;i++)
			h[i]=deg[i]=cnt[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			deg[u]++,deg[v]++;
		}
		scanf("%s",s+1);
		if(n<=2)
		{
			printf("Draw\n");
			continue;
		}
		if(n==3)
		{
			if((s[1]=='W')+(s[2]=='W')+(s[3]=='W')>=2)
				printf("White\n");
			else printf("Draw\n");
			continue;
		}
		int fl=0,ctl=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='W')
			{
				dfs(i,0,1);
				int ct0=0,ct1=0;
				for(int j=1;j<=n;j++)
				{
					if(d[j]==n-1) ct0++;
					if(d[j]==n) ct1++;
				}
				if(ct1)
				{
					ctl++;
					continue;
				}
				if(ct0==2&&n%2) continue;
				fl=1;
				break;
			}
		if(ctl==2&&n%2) fl=1;
		for(int i=1;i<=n;i++)
			if(deg[i]>=4) fl=1;
		if(fl)
		{
			printf("White\n");
			continue;
		}
		mx=-1;
		dfs(1,0,1);
		int u=id;
		mx=-1;
		dfs(u,0,1);
		for(int i=1;i<=n;i++)
			cnt[d[i]]++;
		if(mx>=n-1)
		{
			if(cnt[3]==2||cnt[n-1]==2||mx==n)
				printf("Draw\n");
			else printf("White\n");
			continue;
		}
		if(mx<n-2)
		{
			printf("White\n");
			continue;
		}
		if(cnt[3]==2&&cnt[n-2]==2)
		{
			if(n%2==0) printf("Draw\n");
			else printf("White\n");
		}
		else printf("White\n");
	}
	return 0;
}