//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,k,mxplc[N],dp[N];
vector<ll> v;
char s[N];
multiset<ll> mst;
int main(){
	ll i,p,j;
	scanf("%lld%lld",&n,&k);
	scanf("%s",&s);
	for(i=n;i>0;i--)
	{
		s[i]=s[i-1];
	}
	memset(mxplc,-63,sizeof(mxplc));
	for(i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			v.push_back(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		p=lower_bound(v.begin(),v.end(),i-k)-v.begin();
		if(p==v.size()||v[p]>i)
		{
			continue;
		}
		mxplc[i]=v[p];
	}
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	p=j=0;
	for(i=1;i<=n;i++)
	{
		dp[i]=i+dp[i-1];
		while(j<mxplc[i])
		{
			mst.insert(dp[j]);
			j++;
		}
		while(p<mxplc[i]-k-1)
		{
			mst.erase(mst.lower_bound(dp[p]));
			p++;
		}
		if(mxplc[i]>0)
		{
			dp[i]=min(dp[i],(*mst.begin())+mxplc[i]);
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}