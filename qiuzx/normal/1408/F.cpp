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
using namespace std;
ll n;
vector<pair<ll,ll> > ans;
void rep(ll l,ll r)
{
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1,i;
	rep(l,mid);
	rep(mid+1,r);
	for(i=l;i<=mid&&i+mid-l<=r;i++)
	{
		ans.push_back(make_pair(i,mid+i-l+1));
	}
	return;
}
int main(){
	ll i;
	scanf("%lld",&n);
	for(i=30;i>=0;i--)
	{
		if(n&((ll)1<<i))
		{
			break;
		}
	}
	rep(1,((ll)1<<i));
	rep(n-((ll)1<<i)+1,n);
	printf("%lld\n",(ll)ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld %lld\n",ans[i].F,ans[i].S);
	}
	return 0;
}