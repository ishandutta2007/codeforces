#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int deg[N],st[N],ed[N],cntdfn=0;
vector<int>e[N];
void add_edge(int u,int v)
{
	deg[v]++;
	e[u].push_back(v);
}
void dfs(int now)
{
	st[now]=++cntdfn;
	for (int to:e[now]) dfs(to);
	ed[now]=cntdfn;
}
namespace wcr
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*4],sum[N*4];
	void push_up(int w,int l,int r)
	{
		if (t[w]) sum[w]=r-l+1;
		else if (l==r) sum[w]=0;
		else sum[w]=sum[ls]+sum[rs];
	}
	void add(int w,int l,int r,int ql,int qr,int x)
	{
		if (ql<=l&&r<=qr) return t[w]+=x,push_up(w,l,r);
		if (ql<=mid) add(ls,l,mid,ql,qr,x);
		if (qr>mid) add(rs,mid+1,r,ql,qr,x);
		push_up(w,l,r);
	}
	#undef mid
	#undef rs
	#undef ls
	struct segment
	{
		int x,l,r,y;
		bool operator <(const segment &a)const
		{
			return x<a.x;
		}
	};
	vector<segment>s;
	void add(int x1,int y1,int x2,int y2)
	{
		s.push_back((segment){x1,y1,y2,1});
		s.push_back((segment){x2+1,y1,y2,-1});
	}
	ll solve(int n)
	{
		ll ret=0;
		sort(s.begin(),s.end());
		for (int i=0;i<(int)s.size();i++)
		{
			auto [x,l,r,y]=s[i];
			add(1,1,n,l,r,y);
			if (i+1==(int)s.size()) break;
			ret+=1LL*(s[i+1].x-x)*sum[1];
		}
		return ret/2;
	}
}
void add(int i,int j){wcr::add(st[i],st[j],ed[i],ed[j]),wcr::add(st[j],st[i],ed[j],ed[i]);}

signed main()
{
	int n=read(),m=read(),cnt=0;
	vector<string>a(n);
	vector<vector<int>>id(n,vector<int>(m));
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) id[i][j]=cnt++;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		if (i>0&&a[i-1][j]=='D') add_edge(id[i][j],id[i-2][j]);
		if (i+1<n&&a[i+1][j]=='U') add_edge(id[i][j],id[i+2][j]);
		if (j>0&&a[i][j-1]=='R') add_edge(id[i][j],id[i][j-2]);
		if (j+1<m&&a[i][j+1]=='L') add_edge(id[i][j],id[i][j+2]);
	}
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) if (!deg[id[i][j]]) dfs(id[i][j]);
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		if (a[i][j]=='U') add(id[i][j],id[i+1][j]);
		if (a[i][j]=='L') add(id[i][j],id[i][j+1]);
	}
	print(wcr::solve(n*m));
	
	return 0;
}