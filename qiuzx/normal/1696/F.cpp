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
#define N 110
using namespace std;
string s[N][N];
bool iseq[N][N][N],isok,vis[N];
ll n,dep[N],fa[N],ord[N],par[N],dist[N][N];
vector<pair<ll,ll> > ans;
vector<ll> vt[N];
ll getf(ll x){return (x==fa[x])?x:fa[x]=getf(fa[x]);}
bool cmp(ll x,ll y){return dep[x]<dep[y];}
void solve1(ll x)
{
	ll i,cur=dep[x];
	for(i=0;i<n;i++)
	{
		vis[i]=false;
	}
	vis[x]=true;
	queue<ll> q;
	for(i=0;i<n;i++)
	{
		if(dep[i]==dep[x]+1)
		{
			q.push(i);
			ans.push_back(make_pair(i,x));
			par[i]=x;
			vis[i]=true;
		}
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=0;i<n;i++)
		{
			if(iseq[x][i][par[x]]&&(!vis[i]))
			{
				ans.push_back(make_pair(x,i));
				par[i]=x;
				vis[i]=true;
				q.push(i);
			}
		}
	}
	return;
}
void solve2(ll x,ll y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		vis[i]=false;
	}
	ans.push_back(make_pair(x,y));
	par[x]=y;par[y]=x;
	vis[x]=vis[y]=true;
	queue<ll> q;
	q.push(x),q.push(y);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=0;i<n;i++)
		{
			if(iseq[x][i][par[x]]&&(!vis[i]))
			{
				ans.push_back(make_pair(x,i));
				par[i]=x;
				vis[i]=true;
				q.push(i);
			}
		}
	}
	return;
}
void dfs(ll x,ll lst,ll d,ll beg)
{
	dist[beg][x]=d;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x,d+1,beg);
		}
	}
	return;
}
bool check()
{
	ll i,j,k;
	for(i=0;i<n;i++)
	{
		vt[i].clear();
	}
	for(i=0;i<ans.size();i++)
	{
		vt[ans[i].F].push_back(ans[i].S);
		vt[ans[i].S].push_back(ans[i].F);
	}
	for(i=0;i<n;i++)
	{
		dfs(i,-1,0,i);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(iseq[i][j][k]!=(dist[i][j]==dist[i][k]))
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main(){
	ll T,i,j,k;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					iseq[i][j][k]=false;
				}
			}
		}
		for(i=0;i<n-1;i++)
		{
			for(j=1;j<n-i;j++)
			{
				cin>>s[i][j];
				for(k=0;k<n;k++)
				{
					if(s[i][j][k]=='1')
					{
						iseq[k][i][i+j]=iseq[k][i+j][i]=true;
					}
				}
			}
		}
		isok=true;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j!=i)
				{
					isok&=(!iseq[i][i][j]);
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				fa[j]=j;
			}
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(iseq[i][j][k])
					{
						fa[getf(j)]=getf(k);
					}
				}
			}
			ll tot=0;
			for(j=0;j<n;j++)
			{
				tot+=(getf(j)==j);
				for(k=j+1;k<n;k++)
				{
					if(!iseq[i][j][k])
					{
						isok&=(getf(j)!=getf(k));
					}
				}
			}
			dep[i]=tot;
			ord[i]=i;
		}
		if(!isok)
		{
			puts("No");
			continue;
		}
		sort(ord,ord+n,cmp);
		ans.clear();
		if(dep[ord[0]]==dep[ord[1]])
		{
			if(dep[ord[1]]==dep[ord[2]]&&n>2)
			{
				isok=false;
			}
			else
			{
				solve2(ord[0],ord[1]);
			}
		}
		else
		{
			solve1(ord[0]);
		}
		if(ans.size()!=n-1||(!isok)||(!check()))
		{
			puts("No");
		}
		else
		{
			puts("Yes");
			for(i=0;i<ans.size();i++)
			{
				printf("%lld %lld\n",ans[i].F+1,ans[i].S+1);
			}
		}
	}
	return 0;
}