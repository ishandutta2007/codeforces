#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[22000005];
int h[3000005],tot=0,tin[3000005];
void add(int u,int v)
{
	//printf("u=%d,v=%d\n",u,v);
	e[++tot].v=v;
	e[tot].nxt=h[u];
	h[u]=tot;
	tin[v]++;
}
int cnt,ls[3000005],rs[3000005],rt;
int build(int l,int r)
{
	int x=++cnt;
	if(l==r)
	{
		add(l,x);
		return x;
	}
	int mid=(l+r)/2;
	ls[x]=build(l,mid);
	rs[x]=build(mid+1,r);
	add(ls[x],x);
	add(rs[x],x);
	return x;
}
void modify(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		add(x,v);
		return;
	}
	int mid=(l+r)/2;
	modify(ls[x],l,mid,ql,qr,v);
	modify(rs[x],mid+1,r,ql,qr,v);
}
int t,n,a[1000005],head,tail,q[3000005],tans[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt=n;
		tot=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		rt=build(1,n);
		for(int i=1;i<n;i++)
			if(a[i]!=-1)
			{
				if(i+1<=a[i]-1) modify(rt,1,n,i+1,a[i]-1,i);
				if(a[i]!=n+1)
					add(i,a[i]);
			}
		head=0,tail=0;
		for(int i=1;i<=cnt;i++)
			if(!tin[i])
				q[++tail]=i;
		while(head<tail)
		{
			head++;
			int u=q[head];
			for(int i=h[u];i;i=e[i].nxt)
			{
				int v=e[i].v;
				tin[v]--;
				if(!tin[v]) q[++tail]=v;
			} 
		} 
		if(tail!=cnt)
			printf("-1\n");
		else
		{
			int tt=0;
			for(int i=1;i<=tail;i++)
				if(q[i]<=n)
					tans[q[i]]=++tt;
			for(int i=1;i<=n;i++)
				printf("%d ",tans[i]);
			printf("\n"); 
		}
		for(int i=1;i<=cnt;i++)
			tin[i]=h[i]=0;
		for(int i=1;i<=n;i++)
			a[i]=tans[i]=0;
		for(int i=1;i<=tail;i++)
			q[i]=0;
	}
}