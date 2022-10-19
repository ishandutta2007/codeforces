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
ll n,app[N],sum[N];
pair<ll,pair<ll,ll> > ans,tmp;
int main(){
	ll i,l,r,x;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		app[x]++;
	}
	sum[0]=0;
	for(i=1;i<N;i++)
	{
		sum[i]=app[i]+sum[i-1];
	}
	//[l+1,r-1] has to appear at least twice, and l and r at least once
	ans=make_pair(0,make_pair(0,0));
	for(l=1;l<N;l++)
	{
		if(app[l]==0)
		{
			continue;
		}
		for(r=l+1;r<N;r++)
		{
			if(app[r]<2)
			{
				break;
			}
		}
		if(app[r]==0)
		{
			r--;
		}
		tmp=make_pair(sum[r]-sum[l-1],make_pair(l,r));
		ans=max(ans,tmp);
		if(l==r)
		{
			r++;
		}
		l=r-1;
	}
	printf("%lld\n",ans.F);
	for(i=ans.S.F;i<=ans.S.S;i++)
	{
		while(app[i]>(i>ans.S.F))
		{
			printf("%lld ",i);
			app[i]--;
		}
	}
	for(i=ans.S.S;i>ans.S.F;i--)
	{
		printf("%lld ",i);
	}
	puts("");
	return 0;
}