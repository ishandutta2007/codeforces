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
#define N 100010
#define SQ 300
using namespace std;
ll n,m,fa[N],q,ans[N];
vector<ll> nd,seg;
vector<pair<ll,ll> > vt[N],ed[N],qu;
ll getf(ll x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=getf(fa[x]);
}
int main(){
	ll i,j,k,x,y,z;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--;
		y--;
		z--;
		vt[x].push_back(make_pair(y,z));
		vt[y].push_back(make_pair(x,z));
		ed[z].push_back(make_pair(x,y));
	}
	scanf("%lld",&q);
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		if(x>y)
		{
			swap(x,y);
		}
		qu.push_back(make_pair(x,y));
	}
	for(i=0;i<m;i++)
	{
		if(ed[i].size()>SQ)
		{
			for(j=0;j<n;j++)
			{
				fa[j]=j;
			}
			for(j=0;j<ed[i].size();j++)
			{
				x=ed[i][j].F;
				y=ed[i][j].S;
				x=getf(x);
				y=getf(y);
				if(x==y)
				{
					continue;
				}
				fa[x]=y;
			}
			for(j=0;j<q;j++)
			{
				if(getf(qu[j].F)==getf(qu[j].S))
				{
					ans[j]++;
				}
			}
		}
		else
		{
			nd.clear();
			for(j=0;j<ed[i].size();j++)
			{
				nd.push_back(ed[i][j].F);
				nd.push_back(ed[i][j].S);
			}
			sort(nd.begin(),nd.end());
			nd.erase(unique(nd.begin(),nd.end()),nd.end());
			for(j=0;j<nd.size();j++)
			{
				fa[j]=j;
			}
			for(j=0;j<ed[i].size();j++)
			{
				x=ed[i][j].F;
				y=ed[i][j].S;
				x=lower_bound(nd.begin(),nd.end(),x)-nd.begin();
				y=lower_bound(nd.begin(),nd.end(),y)-nd.begin();
				x=getf(x);
				y=getf(y);
				if(x==y)
				{
					continue;
				}
				fa[x]=y;
			}
			for(j=0;j<nd.size();j++)
			{
				for(k=j+1;k<nd.size();k++)
				{
					if(getf(j)==getf(k))
					{
						seg.push_back(nd[j]*n+nd[k]);
					}
				}
			}
		}
	}
	sort(seg.begin(),seg.end());
	for(i=0;i<q;i++)
	{
		printf("%lld\n",ans[i]+(upper_bound(seg.begin(),seg.end(),qu[i].F*n+qu[i].S)-lower_bound(seg.begin(),seg.end(),qu[i].F*n+qu[i].S)));
	}
	return 0;
}