#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
const ll inf=1000000000000000000;
ll dis[N*20];
int ind[4*N],outd[4*N],n,m,s,cnt;
bool vis[20*N];

struct point
{
	ll t,v;
	bool operator < (const point & o) const
	{
		return v>o.v;
	}
};

vector<point>t[N*20];

inline void add(int x,ll y,ll z)
{
	point u;
	u.t=y,u.v=z;
	t[x].push_back(u);
}

void build(int u,int l,int r)
{
	if (l==r) 
	{
		ind[u]=outd[u]=l;
		return;
	}
	int mid=(l+r)/2;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r); 
	ind[u]=++cnt;
	outd[u]=++cnt;
	add(outd[u*2],outd[u],0);
	add(outd[u*2+1],outd[u],0);
	add(ind[u],ind[u*2],0);
	add(ind[u],ind[u*2+1],0);
}

void update(int u,int l ,int r,int L,int R,ll w,int tp,int fr)
{
	if (L<=l&&R>=r) 
	{
		if (tp==0) add(fr,ind[u],w);
		else add(outd[u],fr,w);
		return;
	}
	int mid=(l+r)/2;
	if (L<=mid) update(u*2,l,mid,L,R,w,tp,fr);
	if (mid<R) update(u*2+1,mid+1,r,L,R,w,tp,fr);
} 


priority_queue<point>q;
void dij()
{
	for (int i=1;i<=cnt;i++) dis[i]=inf;
	dis[s]=0;
	point u;
	u.t=s,u.v=0;
	q.push(u);
	while (!q.empty())
	{
		point v=q.top();
		q.pop();
		if (vis[v.t]==1) continue;
		vis[v.t]=1;
		for (int i=0;i<t[v.t].size();i++) 
		{
			point to=t[v.t][i];
			if (dis[to.t]>dis[v.t]+to.v) 
			{
				dis[to.t]=dis[v.t]+to.v;
				point nxt={to.t,dis[to.t]};
				q.push(nxt);
			}
		}
	}
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int main()
{
	n=read(),m=read(),s=read();
	cnt=n;
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int tp=read();
		if (tp==1)
		{
			int v=read(),l=read(),w=read();
			update(1,1,n,l,l,w,0,v);
		}
		else if  (tp==2)
		{
			int v=read(),l=read(),r=read(),w=read();
			update(1,1,n,l,r,w,0,v);
		} 
		else 
		{
			int v=read(),l=read(),r=read(),w=read();
			update(1,1,n,l,r,w,1,v);
		}
	}
	dij();
	for (int i=1;i<=n;i++) printf("%lld ",dis[i]==inf?-1:dis[i]);
	return 0;
}