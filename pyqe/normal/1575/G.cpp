#include <bits/stdc++.h>

using namespace std;

const long long ma=1e5,dv=1e9+7;
long long n,mb[100069],pc[100069],a[100069],vi[100069],dp[100069];
bitset<100069> vtd;
vector<long long> fz[100069];

int main()
{
	long long i,j,r,k,sz,z=0;
	
	for(i=1;i<=ma;i++)
	{
		mb[i]=1;
	}
	for(i=2;i<=ma;i++)
	{
		if(!vtd[i])
		{
			for(j=i;j<=ma;j+=i)
			{
				vtd[j]=1;
				mb[j]=(mb[j]*(dv-(j%(i*i)!=0)))%dv;
			}
		}
	}
	for(i=1;i<=ma;i++)
	{
		for(j=i;j<=ma;j+=i)
		{
			pc[j]=(pc[j]+mb[j/i]*i)%dv;
			fz[j].push_back(i);
		}
	}
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			sz=fz[a[j]].size();
			for(r=0;r<sz;r++)
			{
				k=fz[a[j]][r];
				if(vi[k]<i*2-1)
				{
					vi[k]=i*2-1;
					dp[k]=0;
				}
				dp[k]++;
			}
		}
		for(j=i;j<=n;j+=i)
		{
			sz=fz[a[j]].size();
			for(r=0;r<sz;r++)
			{
				k=fz[a[j]][r];
				if(vi[k]<i*2)
				{
					vi[k]=i*2;
					z=(z+dp[k]*dp[k]%dv*pc[i]%dv*pc[k])%dv;
				}
			}
		}
	}
	printf("%lld\n",z);
}