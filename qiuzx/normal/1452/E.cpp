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
#define N 2010
using namespace std;
ll n,m,k,lis[N][N],sum[N][N],mx[N],ans=0;
vector<pair<ll,ll> > cont;
ll calc(ll a,ll b,ll l,ll r)
{
	return max((ll)0,min(min(b-a+1,r-l+1),min(r-a+1,b-l+1)));
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
	if(a.F+a.S<b.F+b.S)
	{
		return true;
	}
	if(a.F+a.S>b.F+b.S)
	{
		return false;
	}
	if(a.F<b.F)
	{
		return true;
	}
	if(a.F>b.F)
	{
		return false;
	}
	if(a.S<b.S)
	{
		return true;
	}
	return false;
}
int main(){
	ll i,j,x,y,bk=0;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		cont.push_back(make_pair(x,y));
	}
	sort(cont.begin(),cont.end(),cmp);
	for(i=0;i+k<=n;i++)
	{
		for(j=0;j<m;j++)
		{
			lis[j][i]=calc(cont[j].F,cont[j].S,i,i+k-1);
			sum[j+1][i]=sum[j][i]+lis[j][i];
			mx[j+1]=max(mx[j+1],sum[j+1][i]);
		}
	}
	for(i=0;i+k<=n;i++)
	{
		ans=max(ans,mx[m]);
		bk=0;
		for(j=m-1;j>=0;j--)
		{
			bk+=calc(cont[j].F,cont[j].S,i,i+k-1);
			ans=max(ans,bk+mx[j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}