#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll n,k,pre[N],nxt[N],nid[N],deg[N],lst[N],cnt;
bool vis[N];
queue<ll> q;
vector<ll> app[N],vt[N],ans,seq;
void dfs(ll x)
{
	vis[x]=true;
	nid[x]=cnt;
	app[cnt].push_back(x);
	if(!vis[nxt[x]])
	{
		dfs(nxt[x]);
	}
	else
	{
		if(nxt[x]!=x)
		{
			puts("0");
			exit(0);
		}
	}
	return;
}
bool check()
{
	memset(vis,false,sizeof(vis));
	ll i;
	for(i=0;i<n;i++)
	{
		if(pre[seq[i]]!=-1)
		{
			if(!vis[pre[seq[i]]])
			{
				return false;
			}
		}
		if(nxt[seq[i]]!=seq[i])
		{
			if(i==n-1||seq[i+1]!=nxt[seq[i]])
			{
				return false;
			}
		}
		vis[seq[i]]=true;
	}
	return true;
}
int main(){
	ll i,j,x,y;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		nxt[i]=i;
		lst[i]=i;
		scanf("%lld",&pre[i]);
		pre[i]--;
	}
	for(i=0;i<k;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		nxt[x]=y;
		lst[y]=x;
	}
	cnt=0;
	for(i=0;i<n;i++)
	{
		if(lst[i]!=i)
		{
			continue;
		}
		if(!vis[i])
		{
			dfs(i);
			cnt++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(pre[i]!=-1)
		{
			if(nid[pre[i]]!=nid[i])
			{
				vt[nid[pre[i]]].push_back(nid[i]);
				deg[nid[i]]++;
			}
		}
	}
	memset(vis,false,sizeof(vis));
	for(i=0;i<cnt;i++)
	{
		if(deg[i]==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		x=q.front();
		vis[x]=true;
		q.pop();
		ans.push_back(x);
		for(i=0;i<vt[x].size();i++)
		{
			deg[vt[x][i]]--;
			if(deg[vt[x][i]]==0)
			{
				q.push(vt[x][i]);
			}
		}
	}
	for(i=0;i<cnt;i++)
	{
		if(!vis[i])
		{
			puts("0");
			return 0;
		}
	}
	for(i=0;i<ans.size();i++)
	{
		for(j=0;j<app[ans[i]].size();j++)
		{
			seq.push_back(app[ans[i]][j]);
		}
	}
	if(check())
	{
		for(i=0;i<seq.size();i++)
		{
			printf("%lld ",seq[i]+1);
		}
		puts("");
	}
	else
	{
		puts("0");
	}
	return 0;
}