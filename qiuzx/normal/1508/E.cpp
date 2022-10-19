//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll n,fa[N],f[N][20],dep[N],a[N],dfn[N],id[N],deg[N],cnt0;
vector<ll> vt[N];
void dfs(ll x)
{
	ll i;
	for(i=1;i<20;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(i=0;i<vt[x].size();i++)
	{
		dep[vt[x][i]]=dep[x]+1;
		dfs(vt[x][i]);
	}
	return;
}
ll glca(ll x,ll y)
{
	if(dep[x]<dep[y])
	{
		swap(x,y);
	}
	ll i;
	for(i=19;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y])
		{
			x=f[x][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(i=19;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i],y=f[y][i];
		}
	}
	return f[x][0];
}
void check0(ll x,ll v,ll pre)
{
	if(a[x]<pre&&a[x]>v)
	{
		puts("NO");
		exit(0);
	}
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		check0(vt[x][i],v,(a[x]>v)?max(pre,a[x]):pre);
	}
	return;
}
void check(ll x)
{
	++cnt0;
	if(dfn[x]!=cnt0)
	{
		puts("NO");
		exit(0);
	}
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		check(vt[x][i]);
	}
	return;
}
bool cmp(ll x,ll y)
{
	return (dfn[x]<dfn[y]);
}
int main(){
	ll i,j,x,y;
	fa[0]=-1;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		id[a[i]]=i;
		dfn[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		fa[y]=x;
		vt[x].push_back(y);
		deg[x]++;
		f[y][0]=x;
	}
	dfs(0);
	ll ans=0,cur=-1,cnt=0;
	for(i=1;i<=n;i++)
	{
		ans+=dep[id[i]];
		vector<ll> seq;
		for(j=id[i];j>=0&&dfn[j]==0;j=fa[j])
		{
			seq.push_back(j);
		}
		reverse(seq.begin(),seq.end());
		for(j=0;j<seq.size();j++)
		{
			dfn[seq[j]]=++cnt;
		}
		if((cur!=-1&&glca(cur,id[i])!=cur)||deg[id[i]]!=0)
		{
			break;
		}
		cur=fa[id[i]];
		if(cur>=0)
		{
			deg[cur]--;
		}
	}
	check0(0,i,0);
	for(i=0;i<n;i++)
	{
		if(dfn[i]==0)
		{
			dfn[i]=a[i];
		}
	}
	for(i=0;i<n;i++)
	{
		sort(vt[i].begin(),vt[i].end(),cmp);
	}
	cnt0=0;
	check(0);
	puts("YES");
	printf("%lld\n",ans);
	for(i=0;i<n;i++)
	{
		printf("%lld ",dfn[i]);
	}
	return 0;
}