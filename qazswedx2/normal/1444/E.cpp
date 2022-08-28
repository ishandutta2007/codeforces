#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
struct bint
{
	ull v1,v2;
	bint(){v1=v2=0;}
	bint(ull x):v2(x){v1=0;}
	bint(ull x,ull y):v1(x),v2(y){}
	bool operator<(const bint x) const
	{
		if(v1!=x.v1) return v1<x.v1;
		return v2<x.v2;
	}
};
bint getlas(bint x,int l)
{
	if(l<=63)
		return bint(x.v2&((1ull<<l)-1));
	return bint(x.v1&((1ull<<(l-64))-1),x.v2);
}
int getbit(bint x,int p)
{
	if(p<=63) return (x.v2>>p)&1;
	return (x.v1>>(p-64))&1;
}
void setbit(bint &x,int p)
{
	if(p<=63) x.v2|=(1ull<<p);
	else x.v1|=(1ull<<(p-64));
}
struct edge
{
	int v,w,vis,nxt;
}e[500005];
int n,h[100005],t=1,c[105],qans[105],bt;
int st[105],tp,vis[105];
bint a[105],b[105];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int check(bint q,int l)
{
	tp=0;
	for(int i=1;i<=bt;i++)
		vis[i]=0;
//	if(l==2) printf("check:q=%llu %llu,l=%d\n",q.v1,q.v2,l);
	for(int i=n-1;i>=0;i--)
	{
		int nw=getbit(q,i),ct=0;
		bint mn=bint(1e18,1e18);
		int id=0;
		if(i<l) nw=1;
	//if(l==2)	printf("i=%d,nw=%d\n",i,nw);
		for(int j=1;j<=bt;j++)
			if(!vis[j]&&getbit(b[j],i))
			{
				ct++;
				if(getlas(b[j],i)<mn)
				{
					mn=getlas(b[j],i);
					id=j;
				}
			}
		int ffl=0;
		if(ct)
		{
		//if(!l)	printf("id=%d\n",id);
			for(int j=1;j<=bt;j++)
				if(!vis[j]&&getbit(b[j],i))
				{
					if(j==id)
						continue;
					if(!tp) return 0;
					qans[j]=st[tp--];
					vis[j]=1;
				}
			for(int j=1;j<=bt;j++)
				if(!vis[j]&&getbit(b[j],i)&&j==id)
				{
					if(j==id&&nw&&!tp)
					{
						qans[j]=i;
						ffl=1;
						continue;
					}
					if(!tp) return 0;
					qans[j]=st[tp--];
					vis[j]=1;
				}
		}
		if(nw&&!ffl) st[++tp]=i;
	}
	//if(l==2) printf("ok\n");
	return 1;
}
bint solve()
{
	bint ans;
	for(int i=1;i<=bt;i++)
	{
		b[i].v2++;
		if(!b[i].v2) b[i].v1++;
	//	printf("i=%d,b=%llu %llu\n",i,b[i].v1,b[i].v2);
	}
	for(int i=n-1;i>=0;i--)
		if(!check(ans,i))
			setbit(ans,i);
	check(ans,0);
	for(int i=1;i<=bt;i++)
	{
//		printf("i=%d,c=%d,q=%d\n",i,c[i],qans[i]);
		e[c[i]].w=e[c[i]^1].w=qans[i];
	}
	return ans;
}
void dfs(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}
	bt=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		b[++bt]=a[v];
		c[bt]=i;
	}
	a[u]=solve();
//	printf("u=%d,a=%llu %llu\n",u,a[u].v1,a[u].v2);
}
int mx,mxid;
void dfs2(int u,int fa)
{
//	printf("dfs2:u=%d,fa=%d\n",u,fa);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||e[i].vis) continue;
		if(e[i].w>mx)
		{
			mx=e[i].w;
			mxid=i;
		}
		dfs2(v,u);
	}
}
int main()
{
	//freopen("CF1444E.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
/*	for(int i=2;i<=t;i+=2)
	{
		int u=e[i].v,v=e[i^1].v;
		printf("u=%d,v=%d,w=%d\n",u,v,e[i].w);
	}*/
	int nw=1;
	while(1)
	{
		mx=-1e9;
		dfs2(nw,0);
		if(mx==-1e9)
		{
			printf("! %d\n",nw);
			return 0;
		}
	///	printf("%d\n",mx);
	//	return 0;
		int u=e[mxid].v,v=e[mxid^1].v;
		printf("? %d %d\n",u,v);
		fflush(stdout);
		e[mxid].vis=e[mxid^1].vis=1;
		scanf("%d",&nw);
	}
	return 0;
}