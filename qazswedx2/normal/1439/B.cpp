#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
struct pt
{
	int u,v,nxt;
	pt(int u=0,int v=0,int nxt=0):u(u),v(v),nxt(nxt){}
}a[5000005];
struct edge
{
	int v,nxt;
}e[500005];
struct qt
{
	int val,id;
	qt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const qt x) const
	{
		return val>x.val;
	}
};
int n,m,k,hv,mod=4999997,h2[5000005],at,b[5000005],bt,h[100005],t,tt;
int deg[100005],f[100005],ft,vis[100005];
priority_queue<qt> pq;
int gethash(pt p)
{
	return (p.u+1ll*p.v*hv%mod)%mod;
}
void ins(pt p)
{
	int u=gethash(p);
	b[++bt]=u;
	a[++at]=p;
	a[at].nxt=h2[u];
	h2[u]=at;
}
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t; 
}
int query(pt p)
{
	int u=gethash(p);
	for(int i=h2[u];i;i=a[i].nxt)
	{
		if(a[i].u==p.u&&a[i].v==p.v) return 1;
	}
	return 0;
}
int main()
{
	srand(time(0));
	hv=rand()%100000+96785456;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			h[i]=deg[i]=vis[i]=0;
		for(int i=1;i<=bt;i++)
			h2[b[i]]=0;
		bt=at=t=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			deg[u]++,deg[v]++;
			ins(pt(u,v));
			ins(pt(v,u));
		}
		while(!pq.empty()) pq.pop();
		for(int i=1;i<=n;i++)
			pq.push(qt(deg[i],i));
		int ffl=0;
		while(!pq.empty())
		{
			while(!pq.empty()&&deg[pq.top().id]!=pq.top().val) pq.pop();
			if(pq.empty()) break;
			int u=pq.top().id;
			if(deg[u]>=k) break;
			pq.pop();
			vis[u]=1;
			//printf("u=%d,deg=%d\n",u,deg[u]);
			for(int i=h[u],las=-1;i;i=e[i].nxt)
			{
				int v=e[i].v;
				if(vis[v])
				{
					if(las==-1) h[u]=e[i].nxt;
					else e[las].nxt=e[i].nxt;
					continue;
				} 
				deg[v]--;
				pq.push(qt(deg[v],v));
				las=i;
			}
			if(deg[u]==k-1)
			{
				if(1ll*k*(k-1)/2>m) continue;
				int fl=1;
				ft=1;
				f[ft]=u;
				for(int i=h[u],las=-1;i;i=e[i].nxt)
				{
					int v=e[i].v;
					if(vis[v])
					{
						if(las==-1) h[u]=e[i].nxt;
						else e[las].nxt=e[i].nxt;
						continue;
					} 
					f[++ft]=v;
					las=i;
				}
			/*	printf("u=%d,ft=%d,f=",u,ft);
				for(int i=1;i<=ft;i++)
					printf("%d ",f[i]);
				printf("\n");*/
				for(int i=1;i<=ft&&fl;i++)
					for(int j=i+1;j<=ft;j++)
						if(!query(pt(f[i],f[j])))
						{
							fl=0;
							break;
						}
				if(fl)
				{
					ffl=1;
					printf("2\n");
					for(int i=1;i<=k;i++)
						printf("%d ",f[i]);
					printf("\n");
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(!vis[i]&&!ffl) ffl=2;
		if(!ffl) printf("-1\n");
		else if(ffl==2)
		{
			int ct=0;
			for(int i=1;i<=n;i++)
				if(!vis[i]) ct++;
			printf("1 %d\n",ct);
			for(int i=1;i<=n;i++)
				if(!vis[i])
					printf("%d ",i);
			printf("\n");
		}
	}
	return 0;
}