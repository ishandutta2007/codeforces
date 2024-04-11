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
#define N 500010
using namespace std;
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
	ll random(ll M)
	{
		return nextInt()%M;
	}
}rng;
ll a[N],lst[N],loc[N],occ[N],hash_val[N][3],pre_hash[N],ans=0;
map<ll,ll> mp;
int main(){
	rng.x=18284;
	rng.y=175393;
	rng.z=10573223;
	ll n,i,l,r;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		hash_val[i][0]=rng.random((ll)9371835481685);
		hash_val[i][1]=rng.random((ll)9371835481685);
		hash_val[i][2]=rng.random((ll)9371835481685);
	}
	pre_hash[0]=0;
	for(i=1;i<=n;i++)
	{
		pre_hash[i]^=hash_val[a[i]][occ[a[i]]];
		occ[a[i]]=(occ[a[i]]+1)%3;
		pre_hash[i]^=hash_val[a[i]][occ[a[i]]];
		pre_hash[i]^=pre_hash[i-1];
	}
	/*for(i=0;i<=n;i++)
	{
		cout<<pre_hash[i]<<endl;
	}*/
	memset(occ,0,sizeof(occ));
	l=1;
	mp[0]++;
	for(r=1;r<=n;r++)
	{
		occ[a[r]]++;
		while(occ[a[r]]>3)
		{
			occ[a[l]]--;
			mp[pre_hash[l-1]]--;
			l++;
		}
		//cout<<l<<"~"<<r<<": "<<mp[pre_hash[r]]<<endl;
		ans+=mp[pre_hash[r]];
		mp[pre_hash[r]]++;
	}
	printf("%lld\n",ans);
	return 0;
}