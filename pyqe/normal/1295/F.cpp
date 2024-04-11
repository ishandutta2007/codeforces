#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,as[2069],iv[69],dp[69][169][69],pwk,dv=998244353;
pair<long long,long long> a[1069];
map<long long,long long> com;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

long long cb(long long x,long long y)
{
	long long i,z=1;
	
	y=min(y,x-y);
	for(i=1;i<=y;i++)
	{
		z=z*(x+1-i)%dv*iv[i]%dv;
	}
	return z;
}

int main()
{
	long long i,j,r,u,k,l,ln,sm,z=1;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		iv[i]=pw(i,dv-2);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		k--;
		a[i]={k,l};
		if(!com[k])
		{
			nn++;
			as[nn]=k;
			com[k]=1;
		}
		if(!com[l])
		{
			nn++;
			as[nn]=l;
			com[l]=1;
		}
		z=z*(l-k)%dv;
	}
	sort(as+1,as+nn+1);
	as[nn+1]=as[nn]+1;
	for(i=1;i<=nn;i++)
	{
		com[as[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		a[i].fr=com[a[i].fr];
		a[i].sc=com[a[i].sc]-1;
	}
	dp[0][nn][1]=1;
	for(i=1;i<=n;i++)
	{
		sm=0;
		for(j=nn;j;j--)
		{
			if(j>=a[i].fr&&j<=a[i].sc)
			{
				dp[i][j][1]=sm;
				for(r=2;r<=n;r++)
				{
					dp[i][j][r]=dp[i-1][j][r-1];
				}
			}
			for(r=1;r<=n;r++)
			{
				sm=(sm+dp[i-1][j][r]*cb(as[j+1]-as[j]+r-1,r))%dv;
			}
		}
	}
	sm=0;
	for(i=1;i<=nn;i++)
	{
		for(j=1;j<=n;j++)
		{
			sm=(sm+dp[n][i][j]*cb(as[i+1]-as[i]+j-1,j))%dv;
		}
	}
	z=sm*pw(z,dv-2)%dv;
	printf("%lld\n",z);
}