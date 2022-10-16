#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,sq[70001],pr[70001];
pair<long long,long long> as[70001];
bitset<70001> dp[23334],spc;

int main()
{
	long long i,k,w,p,e,mk;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		as[i]={k,i};
	}
	sort(as+1,as+n+1);
	dp[0]=1;
	for(i=1;i<n;i++)
	{
		k=as[i].fr;
		p=(i-1)/3+1;
		if(i%3==1)
		{
			dp[p]=dp[p-1];
		}
		dp[p]|=dp[p]<<k;
	}
	e=d-as[n].fr;
	if(e<0||!dp[p][e])
	{
		printf("-1\n");
		return 0;
	}
	spc[n]=1;
	for(;p;p--)
	{
		if(!dp[p-1][e])
		{
			for(mk=0;mk<1ll<<min(p*3,n-1)-(p-1)*3;mk++)
			{
				w=0;
				for(i=0;i<3;i++)
				{
					w+=as[(p-1)*3+1+i].fr*(mk>>i&1);
				}
				if(w<=e&&dp[p-1][e-w])
				{
					for(i=0;i<3;i++)
					{
						spc[(p-1)*3+1+i]=mk>>i&1;
					}
					e-=w;
					break;
				}
			}
		}
	}
	spc[0]=1;
	for(i=n;i;i--)
	{
		k=as[i].fr;
		p=as[i].sc;
		sq[p]=k-as[i-1].fr*!spc[i-1];
		pr[p]=as[i-1].sc*!spc[i-1];
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld %lld",sq[i],(long long)!!pr[i]);
		if(pr[i])
		{
			printf(" %lld",pr[i]);
		}
		printf("\n");
	}
}