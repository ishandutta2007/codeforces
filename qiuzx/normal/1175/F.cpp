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
ll n,a[N],rep[N],pre[N],sta[N],ans=0,rd=0;
struct RandGen{
	ll x,y,z;
	ll nextInt()
	{
		ll t=x^(x<<11);
		x=y;
		y=z;
		z^=(z>>19)^t^(t>>8);
		return x;
	}
	ll random()
	{
		return nextInt()%(ll)937183548295;
	}
}rng;
bool check(ll l,ll r)
{
	ll ck;
	if(l==0)
	{
		ck=pre[r];
	}
	else
	{
		ck=pre[r]^pre[l-1];
	}
	if(ck==sta[r-l+1])
	{
		return true;
	}
	return false;
}
int main(){
	ll i,j,mx;
	rng.x=18284;
	rng.y=175393;
	rng.z=10573223;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		rep[i]=rng.random();
		sta[i]=sta[i-1]^rep[i];
	}
	pre[0]=rep[a[0]];
	for(i=1;i<n;i++)
	{
		pre[i]=pre[i-1]^rep[a[i]];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			mx=1;
			for(j=i;j>=0;j--)
			{            
				if(a[j]==1&&j!=i)
				{
					break;
				}
				mx=max(mx,a[j]);
				if(check(j,j+mx-1))
				{
					ans++;
				}
			}
			mx=1;
			for(j=i+1;j<n;j++)
			{
				if(a[j]==1)
				{
					break;
				}
				mx=max(mx,a[j]);
				if(check(j-mx+1,j))
				{
					ans++;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}