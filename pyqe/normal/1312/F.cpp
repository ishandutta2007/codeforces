#include <bits/stdc++.h>

using namespace std;

long long n,d[3],nn,cd,cl,dp[300069][3],a[300069];
map<array<array<long long,3>,5>,long long> ls;
bitset<4> vtd;

long long val(long long x,long long y)
{
	if(x<=0)
	{
		return 0;
	}
	else if(x<cd)
	{
		return dp[x][y];
	}
	else
	{
		return dp[(x-cd)%cl+cd][y];
	}
}

int main()
{
	long long t,rr,i,j,xr,z;
	array<array<long long,3>,5> v,vv;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<3;i++)
		{
			scanf("%lld",d+i);
		}
		nn=0;
		ls.clear();
		for(i=0;i<5;i++)
		{
			for(j=0;j<3;j++)
			{
				v[i][j]=0;
			}
		}
		for(;1;)
		{
			nn++;
			for(i=0;i<3;i++)
			{
				vtd.reset();
				for(j=0;j<3;j++)
				{
					if(!j||j!=i)
					{
						vtd[v[d[j]-1][j]]=1;
					}
				}
				for(j=0;vtd[j];j++);
				dp[nn][i]=j;
			}
			for(i=4;i+1;i--)
			{
				vv[i]=v[i-1];
			}
			for(i=0;i<3;i++)
			{
				vv[0][i]=dp[nn][i];
			}
			if(ls[vv])
			{
				cd=ls[vv];
				cl=nn-cd;
				break;
			}
			ls[vv]=nn;
			v=vv;
		}
		xr=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			xr^=val(a[i],0);
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<3;j++)
			{
				z+=!(xr^val(a[i],0)^val(a[i]-d[j],j));
			}
		}
		printf("%lld\n",z);
	}
}