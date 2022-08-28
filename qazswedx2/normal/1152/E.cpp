#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,vis,nxt;
}e[2000005];
int n,h[500005],b[500005],len,st[500005],tp,maxn[500005],vis[500005],minn[500005],in[500005],t=1,cnt,id;
int cur[500005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	e[t].vis=0;
	h[u]=t;
}
void dfs(int u)
{
	//printf("u=%d\n",u);
	for(int &i=cur[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(e[i].vis) continue;
		e[i].vis=e[i^1].vis=1;
		dfs(v);
	}
	//printf("-u=%d\n",u);
	cur[u]=0;
	st[++tp]=u;
}
void dfs2(int u)
{
	vis[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		dfs2(v);
	}
}
int main()
{
	//freopen("1152E.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d",&minn[i]),b[i]=minn[i];
	for(int i=1;i<n;i++)
		scanf("%d",&maxn[i]),b[i+n-1]=maxn[i];
	sort(b+1,b+2*(n-1)+1);
	len=unique(b+1,b+2*(n-1)+1)-b-1;
	//for(int i=1;i<=len;i++)
	//	printf("%d ",b[i]);
	//printf("\n");
	for(int i=1;i<n;i++)
		minn[i]=lower_bound(b+1,b+len+1,minn[i])-b;
	for(int i=1;i<n;i++)
		maxn[i]=lower_bound(b+1,b+len+1,maxn[i])-b;
	for(int i=1;i<n;i++)
	{
		if(minn[i]>maxn[i]) 
		{
			printf("-1");
			return 0;
		}
		add(minn[i],maxn[i]);
		add(maxn[i],minn[i]);
		in[maxn[i]]++;
		in[minn[i]]++;
		//printf("i=%d,minn=%d,maxn=%d\n",i,minn[i],maxn[i]);
	}
	dfs2(1);
	for(int i=1;i<=len;i++)
		if(!vis[i])
		{
			printf("-1");
			return 0;
		}
	id=1;
	for(int i=1;i<=len;i++)
		if(in[i]%2)
		{
			cnt++;
			id=i;
		}
	if(cnt!=0&&cnt!=2)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=len;i++)
		cur[i]=h[i];
	dfs(id);
	for(int i=tp;i>0;i--)
		printf("%d ",b[st[i]]);
	return 0;
}