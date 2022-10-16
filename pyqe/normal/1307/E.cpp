#include <bits/stdc++.h>

using namespace std;

long long n,m,a[5069],fq[2][5069],p[2][5069],z=-1e18,c=0,dv=1e9+7;
bitset<5069> vtd[5069];

int main()
{
	long long i,j,k,l,mx,sm;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		vtd[k][l]=1;
	}
	vtd[0][1]=1;
	for(i=1;i<=n;i++)
	{
		fq[1][a[i]]++;
		p[1][a[i]]+=vtd[a[i]][fq[1][a[i]]];
	}
	for(i=0;i<=n;i++)
	{
		p[1][a[i]]-=vtd[a[i]][fq[1][a[i]]];
		fq[1][a[i]]--;
		fq[0][a[i]]++;
		if(vtd[a[i]][fq[0][a[i]]])
		{
			mx=!!i;
			sm=1;
			for(j=1;j<=n;j++)
			{
				k=p[0][j];
				l=p[1][j];
				k*=j!=a[i];
				l-=j==a[i]&&fq[1][j]>=fq[0][j];
				if(k>l)
				{
					swap(k,l);
				}
				if(!k)
				{
					if(l)
					{
						mx++;
						sm=sm*l%dv;
					}
				}
				else if(k==1&&l==1)
				{
					mx++;
					sm=sm*2%dv;
				}
				else
				{
					mx+=2;
					sm=sm*k%dv*(l-1)%dv;
				}
			}
			if(mx>z)
			{
				z=mx;
				c=0;
			}
			if(mx==z)
			{
				c=(c+sm)%dv;
			}
			p[0][a[i]]++;
		}
	}
	printf("%lld %lld\n",z,c);
}