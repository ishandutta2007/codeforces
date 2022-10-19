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
#define N 5010
using namespace std;
ll n,x0,y0,px[N],py[N];
pair<ll,ll> mn;
set<ll> lft;
ll dist(ll x,ll y,ll a,ll b)
{
	return (x-a)*(x-a)+(y-b)*(y-b);
}
int main(){
	ll i,j,x,y;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&px[i],&py[i]);
		lft.insert(i);
	}
	x0=y0=0;
	for(i=0;i<n;i++)
	{
		mn=make_pair(-LINF,-1);
		for(j=0;j<n;j++)
		{
			if(lft.find(j)!=lft.end())
			{
				mn=max(mn,make_pair(dist(px[j],py[j],x0,y0),j));
			}
		}
		x0=px[mn.S];
		y0=py[mn.S];
		lft.erase(lft.lower_bound(mn.S));
		printf("%lld ",mn.S+1);
	}
	puts("");
	return 0;
}