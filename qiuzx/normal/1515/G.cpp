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
#define N 200010 
using namespace std;
ll n,m,cnt=0,cnt2=0,bel[N],din[N],lw[N],gd[N],dist[N],q;
bool vis[N],inq[N];
vector<pair<ll,ll> > vt[N];
vector<ll> sz[N];
stack<ll> st;
void getscc(ll x)
{
	vis[x]=inq[x]=true;
	st.push(x);
	din[x]=lw[x]=++cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i].F])
		{
			getscc(vt[x][i].F);
			lw[x]=min(lw[x],lw[vt[x][i].F]);
		}
		else if(inq[vt[x][i].F])
		{
			lw[x]=min(lw[x],din[vt[x][i].F]);
		}
	}
	if(lw[x]==din[x])
	{
		do
		{
			i=st.top();
			st.pop();
			inq[i]=false;
			sz[cnt2].push_back(i);
		}while(i!=x);
		cnt2++;
	}
	return;
}
void dfs2(ll x,ll d)
{
	dist[x]=d;
	vis[x]=true;
	ll i,nd;
	for(i=0;i<vt[x].size();i++)
	{
		if(bel[vt[x][i].F]!=bel[x])
		{
			continue;
		}
		if(!vis[vt[x][i].F])
		{
			dfs2(vt[x][i].F,d+vt[x][i].S);
		}
		else
		{
			nd=dist[x]-dist[vt[x][i].F]+vt[x][i].S;
			gd[bel[x]]=__gcd(gd[bel[x]],nd);
		}
	}
	return;
}
int main(){
	ll i,j,x,y,z,v;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--;
		y--;
		vt[x].push_back(make_pair(y,z));
	}
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			getscc(i);
		}
	}
	for(i=0;i<cnt2;i++)
	{
		for(j=0;j<sz[i].size();j++)
		{
			bel[sz[i][j]]=i;
		}
	}
	memset(vis,false,sizeof(vis));
	for(i=0;i<cnt2;i++)
	{
		gd[i]=0;
		dfs2(sz[i][0],0);
	}
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--;
		v=__gcd(gd[bel[x]],z);
		if(y%v==0)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}