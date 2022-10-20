#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
const ll inf=1LL<<60;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	ll to,nxt;
}e[N];
ll head[N*2],cnt=0;
void add(ll u,ll v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
ll fa[N],deep[N],dp[N],a[N];
vector<ll>v[N];
void clear(ll n)
{
	for (ll i=1;i<=n;i++)
	{
		head[i]=0;
		v[i].clear();
	}
	cnt=0;
}
void dfs(ll x)
{
	deep[x]=deep[fa[x]]+1;
	v[deep[x]].push_back(x);
	for (ll i=head[x];i;i=e[i].nxt) dfs(e[i].to);
}
bool cmp(ll x,ll y)
{
	return a[x]<a[y];
}

signed main()
{
	ll T=read();
	while (T--)
	{
		deep[0]=-1;
		dp[0]=0;
		ll n=read(),ans=0;
		for (ll i=2;i<=n;i++)
		{
			fa[i]=read();
			add(fa[i],i);
		}
		for (ll i=2;i<=n;i++) a[i]=read();
		dfs(1);
		for (ll d=1;d<=n;d++)
		{
			if (v[d].empty()) break;
			sort(v[d].begin(),v[d].end(),cmp);
			ll Min=a[v[d][0]],Max=a[v[d].back()];
			for (ll i=0;i<(ll)v[d].size();i++)
			{
				ll x=v[d][i];
				dp[x]=dp[fa[x]]+max(a[x]-Min,Max-a[x]);
			}
			Max=-inf;
			for (ll i=0;i<(ll)v[d].size();i++)
			{
				ll x=v[d][i];
				dp[x]=max(dp[x],Max+a[x]);
				Max=max(Max,dp[fa[x]]-a[x]);
			}
			Max=-inf;
			for (ll i=v[d].size()-1;i>=0;i--)
			{
				ll x=v[d][i];
				ans=max(ans,dp[x]=max(dp[x],Max-a[x]));
				Max=max(Max,dp[fa[x]]+a[x]);
			}
		}
		print(ans);
		clear(n);
	}

	return 0;
}