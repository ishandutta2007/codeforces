#include <bits/stdc++.h>

using namespace std;

long long nn,a[8][3],as[28],inf=1e18;
bitset<8> vtd;

void rk(long long x)
{
	if(x<8)
	{
		for(;1;)
		{
			rk(x+1);
			if(!x||!next_permutation(a[x],a[x]+3))
			{
				break;
			}
		}
	}
	else
	{
		long long i,j,r,k;
		
		nn=0;
		for(i=0;i<8;i++)
		{
			for(j=i+1;j<8;j++)
			{
				as[nn]=0;
				for(r=0;r<3;r++)
				{
					k=a[i][r]-a[j][r];
					as[nn]+=k*k;
				}
				nn++;
			}
		}
		sort(as,as+nn);
		if(!as[0])
		{
			return;
		}
		for(i=0;i<nn;i++)
		{
			if(as[i]!=as[0]*(1ll+(i>=12)+(i>=24)))
			{
				return;
			}
		}
		printf("YES\n");
		for(i=0;i<8;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%lld%c",a[i][j]," \n"[j==2]);
			}
		}
		exit(0);
	}
}

int main()
{
	long long i,j;
	
	for(i=0;i<8;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%lld",&a[i][j]);
		}
		sort(a[i],a[i]+3);
	}
	rk(0);
	printf("NO\n");
}