#include <bits/stdc++.h>

using namespace std;

const long long ma=1e5;
long long n,ls[100069],pr[100069][17];
vector<long long> fz[100069];

int main()
{
	long long t,rr,i,j,k,l,sz,mx=0,z;
	
	for(i=2;i<=ma;i++)
	{
		if(fz[i].empty())
		{
			for(j=i;j<=ma;j+=i)
			{
				fz[j].push_back(i);
			}
		}
	}
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sz=fz[k].size();
		for(j=0;j<sz;j++)
		{
			l=fz[k][j];
			mx=max(mx,ls[l]);
			ls[l]=i;
		}
		pr[i][0]=mx;
		for(j=1;j<17;j++)
		{
			pr[i][j]=pr[pr[i][j-1]][j-1];
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z=0;
		for(i=16;i+1;i--)
		{
			if(pr[l][i]>=k)
			{
				z|=1ll<<i;
				l=pr[l][i];
			}
		}
		z++;
		printf("%lld\n",z);
	}
}