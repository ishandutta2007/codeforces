#include <bits/stdc++.h>
#define ll int
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 5010
#define M 100010
using namespace std;
ll a[M];
struct SegT{
	ll lo[M<<2],hi[M<<2],val[M<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r;
		if(l==r)
		{
			val[x]=a[l];
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		val[x]=max(val[a],val[a|1]);
		return;
	}
	ll query(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return val[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1,ret=0;
		if(mid>=l)
		{
			ret=query(a,l,r);
		}
		if(mid<r)
		{
			ret=max(ret,query(a|1,l,r));
		}
		return ret;
	}
}segt;
ll n,m,par[N];
vector<ll> vt[N];
vector<pair<pair<ll,ll>,pair<ll,double> > > qry;
double dp[N][N];
bool cmp(pair<pair<ll,ll>,pair<ll,double> > x,pair<pair<ll,ll>,pair<ll,double> > y)
{
	if(x.F.F<y.F.F)
	{
		return true;
	}
	if(x.F.F>y.F.F)
	{
		return false;
	}
	return (x.F.S>y.F.S);
}
void dfs(ll x)
{
	ll i,j;
	dp[x][0]=(double)1.0-qry[x].S.S;
	for(i=0;i<vt[x].size();i++)
	{
		dfs(vt[x][i]);
		if(qry[x].S.F-qry[vt[x][i]].S.F<=m)
		{
			dp[x][0]*=dp[vt[x][i]][qry[x].S.F-qry[vt[x][i]].S.F];
		}
	}
	for(j=1;j<=m;j++)
	{
		double p1=qry[x].S.S,p2=(double)1.0-qry[x].S.S;
		for(i=0;i<vt[x].size();i++)
		{
			if(qry[x].S.F-qry[vt[x][i]].S.F+j<=m)
			{
				p2*=dp[vt[x][i]][qry[x].S.F-qry[vt[x][i]].S.F+j];
			}
			if(qry[x].S.F-qry[vt[x][i]].S.F-1+j<=m)
			{
				p1*=dp[vt[x][i]][qry[x].S.F-qry[vt[x][i]].S.F-1+j];
			}
		}
		dp[x][j]=p1+p2;
	}
	return;
}
int main(){
	ll i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	segt.build(1,0,n-1);
	for(i=0;i<m;i++)
	{
		ll x,y;
		double d;
		scanf("%d%d%lf",&x,&y,&d);
		x--;
		y--;
		qry.push_back(make_pair(make_pair(x,y),make_pair(segt.query(1,x,y),d)));
	}
	qry.push_back(make_pair(make_pair(0,n-1),make_pair(segt.query(1,0,n-1),0)));
	sort(qry.begin(),qry.end(),cmp);
	for(i=1;i<qry.size();i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(qry[j].F.F<=qry[i].F.F&&qry[j].F.S>=qry[i].F.S)
			{
				par[i]=j;
				vt[j].push_back(i);
				break;
			}
		}
	}
	dfs(0);
	double ans=(double)qry[0].S.F*dp[0][0];
	for(i=1;i<=m;i++)
	{
		ans+=(double)(qry[0].S.F+i)*(dp[0][i]-dp[0][i-1]);
	}
	printf("%.10lf\n",ans);
	return 0;
}