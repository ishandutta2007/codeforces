#include <bits/stdc++.h>

using namespace std;

const long long mm=500,inf=1e18;
long long n,m;
bitset<mm> a[60][2][2][mm],a0,az;

int main()
{
	long long i,j,r,ii,k,l,w,z=0;
	bool e=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		k--;
		l--;
		a[0][w][0][k][l]=1;
		a[0][w][1][l][k]=1;
	}
	for(i=1;i<60;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(j=0;j<mm;j++)
			{
				for(r=0;r<mm;r++)
				{
					a[i][ii][0][j][r]=(a[i-1][ii][0][j]&a[i-1][!ii][1][r]).any();
					a[i][ii][1][r][j]=a[i][ii][0][j][r];
				}
			}
		}
	}
	a0[0]=1;
	for(i=59;i+1;i--)
	{
		az.reset();
		for(j=0;j<mm;j++)
		{
			if(a0[j])
			{
				az|=a[i][e][0][j];
			}
		}
		if(az.any())
		{
			z|=1ll<<i;
			a0=az;
			e^=1;
		}
	}
	if(z>inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}