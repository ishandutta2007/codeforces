// By: Little09
// Problem: CF1163F Indecisive Taxi Fee
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1163F
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1000000000000000000;
const int N=6e5+5,M=6e5+5;
int n,m;
inline ll read()
{
    ll F=1,ANS=0;
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
namespace ST
{
	ll sum[N*4],add[N*4];
	inline void push_up(int u)
	{
		sum[u]=min(sum[u*2],sum[u*2+1]);
	}
	inline void push_down(int u)
	{
		if (add[u]!=inf)
		{
			sum[u*2]=min(sum[u*2],add[u]);
			sum[u*2+1]=min(sum[u*2+1],add[u]);
			add[u*2]=min(add[u*2],add[u]);
			add[u*2+1]=min(add[u*2+1],add[u]);
			add[u]=inf;
		}
	}
	void build(int u,int l,int r)
	{
		add[u]=inf;
		if (l==r)
		{
			sum[u]=inf;
			add[u]=inf;
			return;
		}
		int mid=(l+r)>>1;
		build(u*2,l,mid);
		build(u*2+1,mid+1,r);
		push_up(u);
	}
	ll ask(int u,int L,int R,int l,int r)
	{
		if (l<=L&&R<=r) return sum[u];
		int mid=(L+R)>>1;
		push_down(u);
		ll res=inf;
		if (l<=mid) res=min(res,ask(u*2,L,mid,l,r));
		if (mid<r) res=min(res,ask(u*2+1,mid+1,R,l,r));
		return res;
	}
	void change(int u,int L,int R,int l,int r,ll k)
	{
		if (l>r) return;
		if (l<=L&&R<=r) 
		{
			sum[u]=min(sum[u],k);
			add[u]=min(add[u],k);
			return;
		}
		int mid=(L+R)>>1;
		push_down(u);
		if (l<=mid) change(u*2,L,mid,l,r,k);
		if (mid<r) change(u*2+1,mid+1,R,l,r,k);
		push_up(u);
	}
}

namespace G
{
	int cnt,t[M],nxt[M],w[M],h[N];
	ll dis[N][2],v[M],Z[M];
	int a[N],tot,b[N],ed[M];
	int X[M],Y[M],L[N][2],pre[N],pr[N];
	inline void add(int x,int y,int z)
	{
		cnt++;
		t[cnt]=y;
		nxt[cnt]=h[x];
		v[cnt]=z;
		h[x]=cnt;
	}
	bool used[N];
	bool flag[N];
	bool path[N];
	priority_queue<pair<ll,int> >q; 
	void dijkstra(int s,int tp,int op)
	{
		for (int i=0;i<=n;i++) dis[i][tp]=inf;
		for (int i=0;i<=n;i++) used[i]=0;
		if (op==0) for (int i=0;i<=n;i++) pre[i]=-1;
		if (op==0) for (int i=0;i<=n;i++) pr[i]=-1;
	    dis[s][tp]=0;
	    L[s][tp]=b[s]-1;
	    q.push(make_pair(0,s));
	    while (q.size())
	    {
	    	int x=q.top().second;
	    	q.pop();
	    	if (used[x]) continue;
	    	used[x]=1;
	    	for (int j=h[x];j;j=nxt[j])
	    	{
	    		if (used[t[j]]) continue;
	    		if (dis[t[j]][tp]>dis[x][tp]+v[j])
	    		{
	    			dis[t[j]][tp]=dis[x][tp]+v[j];
	    			if (op==0)
	    			{
	    				pre[t[j]]=j;
	    				pr[t[j]]=x;
	    			}
	    			else
	    			{
	    				if (flag[t[j]]==1) 
	    				{
	    					L[t[j]][tp]=b[t[j]]-1;
	    				}
	    				else L[t[j]][tp]=L[x][tp];
	    			}
	    			q.push(make_pair(-dis[t[j]][tp],t[j]));
				}
			}
		}
	}
	void fff(int x)
	{
		flag[x]=1;
		b[x]=tot+1;
		if (pr[x]!=-1) 
		{
			path[pre[x]]=1;
			a[++tot]=pre[x];
			ed[pre[x]]=tot;
			fff(pr[x]);
		}
	}
	void work()
	{
		for (int i=1;i<=m;i++)
		{
			X[i]=read(),Y[i]=read();
			Z[i]=read();
			add(X[i],Y[i],Z[i]);
			add(Y[i],X[i],Z[i]);
		}
		dijkstra(n,1,0);
		fff(1);
		dijkstra(1,0,1);
		dijkstra(n,1,1);
		ST::build(1,1,tot);
		for (int i=1;i<=m;i++)
		{
			if (path[i*2]==1||path[i*2-1]==1) continue;
			ll len=Z[i]+min(dis[X[i]][0]+dis[Y[i]][1],dis[X[i]][1]+dis[Y[i]][0]);
			ST::change(1,1,tot,L[X[i]][0]+1,L[Y[i]][1],len);
			ST::change(1,1,tot,L[Y[i]][0]+1,L[X[i]][1],len);
		}
	}
	void ask()
	{
		int x=read();
		ll y=read();
		ll ans=0;
		if (y<Z[x])
		{
			if (path[x*2]==1||path[x*2-1]==1)
			{
				ans=dis[n][0]+y-Z[x];
			}
			else
			{
				ans=dis[n][0];
				ans=min(ans,dis[X[x]][0]+y+dis[Y[x]][1]);
				ans=min(ans,dis[Y[x]][0]+y+dis[X[x]][1]);
			}
		}
		else
		{
			if (path[x*2]==1)
			{
				ll p=ST::ask(1,1,tot,ed[x*2],ed[x*2]);
				ans=min(dis[n][0]+y-Z[x],p);
			}
			else if (path[x*2-1]==1)
			{
				ll p=ST::ask(1,1,tot,ed[x*2-1],ed[x*2-1]);
				ans=min(dis[n][0]+y-Z[x],p);
			}
			else
			{
				ans=dis[n][0];
			}
		}
		printf("%lld\n",ans);
	}
}
int main()
{
	n=read(),m=read();
	int T=read();
	G::work();
	while (T--)
	{
		G::ask();
	}
	return 0;
}