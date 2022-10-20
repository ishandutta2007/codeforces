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
using namespace std;
bool on_path[N];
ll n,m,dist[N],min0[N],lst[N];
vector<pair<pair<ll,ll>,ll> > ed,vt[N],ans;
priority_queue<pair<pair<ll,ll>,ll> > pq;
void retrack(ll x)
{
	if(lst[x]==-1)
	{
		return;
	}
	on_path[lst[x]]=true;
	if(ed[lst[x]].F.F==x)
	{
		retrack(ed[lst[x]].F.S);
	}
	else
	{
		retrack(ed[lst[x]].F.F);
	}
	return;
}
int main(){
	ll i,x,y,z;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--;
		y--;
		vt[x].push_back(make_pair(make_pair(y,z),i));
		vt[y].push_back(make_pair(make_pair(x,z),i));
		ed.push_back(make_pair(make_pair(x,y),z));
	}
	memset(dist,127,sizeof(dist));
	memset(min0,127,sizeof(min0));
	memset(lst,-1,sizeof(lst));
	dist[0]=min0[0]=0;
	pq.push(make_pair(make_pair(0,0),0));
	while(!pq.empty())
	{
		x=pq.top().S;
		y=-pq.top().F.F;
		z=-pq.top().F.S;
		pq.pop();
		if(dist[x]!=y||min0[x]!=z)
		{
			continue;
		}
		for(i=0;i<vt[x].size();i++)
		{
			if(dist[vt[x][i].F.F]>y+1)
			{
				dist[vt[x][i].F.F]=y+1;
				min0[vt[x][i].F.F]=z+(vt[x][i].F.S^1);
				lst[vt[x][i].F.F]=vt[x][i].S;
				pq.push(make_pair(make_pair(-dist[vt[x][i].F.F],-min0[vt[x][i].F.F]),vt[x][i].F.F));
			}
			else if(dist[vt[x][i].F.F]==y+1)
			{
				if(min0[vt[x][i].F.F]>z+(vt[x][i].F.S^1))
				{
					min0[vt[x][i].F.F]=z+(vt[x][i].F.S^1);
					lst[vt[x][i].F.F]=vt[x][i].S;
					pq.push(make_pair(make_pair(-dist[vt[x][i].F.F],-min0[vt[x][i].F.F]),vt[x][i].F.F));
				}
			}
		}
	}
	memset(on_path,false,sizeof(on_path));
	retrack(n-1);
	for(i=0;i<ed.size();i++)
	{
		if(on_path[i])
		{
			if(ed[i].S==0)
			{
				ans.push_back(make_pair(ed[i].F,1));
			}
		}
		else
		{
			if(ed[i].S==1)
			{
				ans.push_back(make_pair(ed[i].F,0));
			}
		}
	}
	printf("%lld\n",(ll)ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld %lld %lld\n",ans[i].F.F+1,ans[i].F.S+1,ans[i].S);
	}
	return 0;
}