#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[1000005];
int n,a[100005],prime[1000005],pt,p[1000005],pn=1e6,sn,dis[1000005],pre[1000005];
int ans,rp[1000005],q[1000005],head,tail;
int h[1000005],t=1;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void ins(int x)
{
	int b[3],c[3],ct=0;
	b[0]=b[1]=c[0]=c[1]=0;
	for(int i=1;i<=sn;i++)
		if(x%prime[i]==0)
		{
			b[ct]=i,c[ct]=0;
			while(x%prime[i]==0) x/=prime[i],c[ct]++;
			ct++;
		}
	if(x!=1)
	{
		b[ct]=rp[x],c[ct]=1;
		ct++;
	}
	c[0]&=1,c[1]&=1;
	if(c[0]+c[1]==0)
	{
		ans=1;
		return;
	}
	if(c[0]+c[1]==1)
	{
		if(!c[0]) b[0]=0;
		if(!c[1]) b[1]=0;
	}
//	printf("i=%d,b=%d,%d\n",x,b[0],b[1]);
	add(b[0],b[1]);
	add(b[1],b[0]);
}
int main()
{
	for(int i=2;i<=pn;i++)
	{
		if(!p[i])
		{
			prime[++pt]=i;
			rp[i]=pt;
		}
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	while(prime[sn+1]<=1e3) sn++;
	ans=1e9;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ins(a[i]);
	}
	for(int i=0;i<=sn;i++)
	{
		for(int j=0;j<=pt;j++)
			dis[j]=1e9;
		head=1,tail=1;
		q[head]=i;
		pre[i]=-1;
		dis[i]=0;
		while(head<=tail)
		{
			int u=q[head];
			head++;
			for(int j=h[u];j;j=e[j].nxt)
			{
				int v=e[j].v;
				if(pre[u]==(j^1)) continue;
			//	printf("u=%d,v=%d,p=%d,j=%d,dis=%d,%d\n",u,v,pre[u],j,dis[u],dis[v]);
				ans=min(ans,dis[u]+dis[v]+1);
				if(dis[v]>dis[u]+1)
				{
					pre[v]=j;
					dis[v]=dis[u]+1;
					q[++tail]=v;
				}
			}
		}
	}
	if(ans<1e8) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}