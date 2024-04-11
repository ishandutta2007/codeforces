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
ll n,m,a[N],b[N],mxtot=0,ans=0,fa[N];
vector<pair<ll,pair<ll,ll> > > ed;
ll getf(ll x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=getf(fa[x]);
}
int main(){
	ll i,j,s,x,y;
	scanf("%lld%lld",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&s);
		for(j=0;j<s;j++)
		{
			scanf("%lld",&x);
			x--;
			ed.push_back(make_pair(-(a[i]+b[x]),make_pair(x,i+n)));
			mxtot+=a[i]+b[x];
		}
	}
	sort(ed.begin(),ed.end());
	for(i=0;i<n+m;i++)
	{
		fa[i]=i;
	}
	for(i=0;i<ed.size();i++)
	{
		s=ed[i].F;
		x=ed[i].S.F;
		y=ed[i].S.S;
		if(getf(x)==getf(y))
		{
			continue;
		}
		x=getf(x);
		y=getf(y);
		ans+=s;
		fa[x]=y;
	}
	printf("%lld\n",mxtot+ans);
	return 0;
}