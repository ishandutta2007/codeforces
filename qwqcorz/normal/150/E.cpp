#include<bits/stdc++.h>
#define ll long long
#define piir pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n,L,R,u,v;
struct edge{int to,val;};
vector<edge>e[N];
vector<int>t[N];
int siz[N],rt,fa[N];
bool del[N];
namespace findroot
{
	int siz[N],mx[N];
	void dfs(int now,int father,int tot)
	{
		siz[now]=1,mx[now]=0;
		for (edge i:e[now])
		{
			int to=i.to;
			if (to==father||del[to]) continue;
			dfs(to,now,tot);
			siz[now]+=siz[to];
			mx[now]=max(mx[now],siz[to]);
		}
		mx[now]=max(mx[now],tot-siz[now]);
		if (mx[now]<=tot/2) rt=now;
	}
}
void build(int now,int father,int tot)
{
	rt=0,findroot::dfs(now,father,tot);
	t[father].push_back(rt);
	fa[rt]=father;
	siz[rt]=tot;
//	print(rt,':'),print(father,' '),print(tot);
	int x=rt;
	findroot::dfs(x,father,tot);
	del[x]=1;
	for (edge i:e[x])
	{
		int to=i.to;
		if (to==father||del[to]) continue;
		build(to,x,findroot::siz[to]);
	}
}
int getdeep(int now,int father)
{
	int ret=0;
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father||del[to]) continue;
		ret=max(ret,getdeep(to,now));
	}
	return ret+1;
}
void get(int now,int father,int dis,int sum,int k,vector<piir>&a)
{
	a[dis]=max(a[dis],mk(sum,now));
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father||del[to]) continue;
		get(to,now,dis+1,sum+(i.val>=k?1:-1),k,a);
	}
}
bool merge(vector<piir>&a,vector<piir>&b)
{
	static int q[N];
	int n=a.size(),m=b.size(),h=1,t=0;
	for (int i=m-1,j=0;i>=0;i--)
	{
		while (j<n&&j+i<=R)
		{
			while (h<=t&&a[q[t]]<=a[j]) t--;
			q[++t]=j++;
		}
		while (h<=t&&q[h]+i<L) h++;
		if (h<=t&&a[q[h]].fi+b[i].fi>=0) return u=a[q[h]].se,v=b[i].se,1;
	}
	for (int i=0;i<m;i++) a[i]=max(a[i],b[i]);
	return 0;
}
bool dfz(int now,int k)
{
	int cnt=0;
	vector<int>p;
	vector<vector<piir>>a;
	for (edge i:e[now])
	{
		int to=i.to;
		if (del[to]) continue;
		vector<piir>tmp(getdeep(to,now)+1);
		for (auto &i:tmp) i.fi=-N;
		get(to,now,1,i.val>=k?1:-1,k,tmp);
		a.push_back(tmp);
		p.push_back(cnt++);
	}
	a.push_back(vector<piir>({mk(0,now)}));
	p.push_back(cnt++);
	sort(p.begin(),p.end(),[&](int x,int y){
		return a[x].size()<a[y].size();
	});
	for (int i=1;i<(int)p.size();i++)
	if (merge(a[p[i]],a[p[i-1]])) return 1;
	del[now]=1;
	for (int to:t[now])
	{
		if (del[to]) continue;
		if (dfz(to,k)) return 1;
	}
	return 0;
}
bool check(int mid)
{
	memset(del,0,sizeof(del));
	return dfz(rt,mid);
}
int b[N];

signed main()
{
	n=read(),L=read(),R=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=b[i]=read();
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	sort(b+1,b+n);
	build(1,0,n),rt=t[0][0];
	int l=1,r=n-1;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(b[mid])) l=mid+1;
					  else r=mid-1;
	}
	check(b[r]);
	print(u,' '),print(v);
	
	return 0;
}