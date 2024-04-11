#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[300069],dp[300069],sz;
vector<pair<long long,long long>> v;

int main()
{
	long long i,lh,rh,md,z=-1,k;
	bool bad;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	lh=0;
	rh=a[n]-a[1];
	for(md=(lh+rh)/2;lh<=rh;md=(lh+rh)/2)
	{
		bad=0;
		v.clear();
		sz=0;
		for(i=1;i<=n;i++)
		{
			k=upper_bound(v.begin(),v.end(),mp(a[i]-md,(long long)0))-v.begin();
			if(i==1||i-dp[i-1]>=d)
			{
				v.push_back(mp(a[i],i));
				sz++;
			}
			else if(k==sz)
			{
				bad=1;
				break;
			}
			dp[i]=v[k].sc;
		}
		if(n+1-dp[n]<d)
		{
			bad=1;
		}
		if(bad)
		{
			lh=md+1;
		}
		else
		{
			z=md;
			rh=md-1;
		}
	}
	printf("%lld\n",z);
}