#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,as[6069],dp[6069],sq[3069];
pair<long long,long long> a[3069];

long long fd(long long x)
{
	return lower_bound(as+1,as+n*2+1,x)-as;
}

int main()
{
	long long t,rr,i,j,r,k,l,lb,rb,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&k,&l);
			k--;
			a[i]={l,k};
			as[i*2-1]=k;
			as[i*2]=l;
		}
		sort(as+1,as+n*2+1);
		for(i=1;i<=n;i++)
		{
			a[i].fr=fd(a[i].fr);
			a[i].sc=-fd(a[i].sc);
		}
		sort(a+1,a+n+1);
		a[n+1]={n*2,0};
		for(i=1;i<=n+1;i++)
		{
			lb=-a[i].sc;
			rb=a[i].fr;
			mx=0;
			for(r=0,j=1;j<i;j++)
			{
				k=-a[j].sc;
				l=a[j].fr;
				for(;r<l;r++)
				{
					dp[r]=mx;
				}
				if(k>=lb&&l<=rb)
				{
					mx=max(mx,dp[k]+sq[j]+1);
				}
			}
			sq[i]=mx;
		}
		printf("%lld\n",sq[n+1]);
	}
}