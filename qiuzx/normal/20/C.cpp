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
bool inq[N];
ll n,m,dist[N],lst[N];
vector<pair<ll,ll> > vt[N];
queue<ll> q;
void print(ll x)
{
	if(x==-1)
	{
		return;
	}
	print(lst[x]);
	printf("%lld ",x+1);
	return;
}
bool cmp(pair<ll,ll> x,pair<ll,ll> y)
{
	if(x.S<y.S)
	{
		return true;
	}
	return false;
}
int main(){
	ll i,x,y,z;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--;
		y--;
		vt[x].push_back(make_pair(y,z));
		vt[y].push_back(make_pair(x,z));
	}
	for(i=0;i<n;i++)
	{
		sort(vt[i].begin(),vt[i].end(),cmp);
	}
	memset(dist,127,sizeof(dist));
	dist[0]=0;
	memset(inq,0,sizeof(inq));
	q.push(0);
	inq[0]=true;
	memset(lst,-1,sizeof(lst));
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		inq[x]=false;
		for(i=0;i<vt[x].size();i++)
		{
			if(dist[vt[x][i].F]>dist[x]+vt[x][i].S)
			{
				dist[vt[x][i].F]=dist[x]+vt[x][i].S;
				lst[vt[x][i].F]=x;
				if(!inq[vt[x][i].F])
				{
					q.push(vt[x][i].F);
					inq[vt[x][i].F]=true;
				}
			}
		}
	}
	if(dist[n-1]>=LINF)
	{
		puts("-1");
	}
	else
	{
		print(n-1);
		puts("");
	}
	return 0;
}