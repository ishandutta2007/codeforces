#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,j,ii,jj,k,sz,sz2,z;
	
	scanf("%lld%lld",&n,&m);
	if(n==m)
	{
		z=1;
	}
	else if(m%2==0)
	{
		z=0;
	}
	else
	{
		for(sz2=0;1ll<<sz2<=m;sz2++);
		n=n<<1|1;
		for(ii=0;ii<2;ii++)
		{
			for(sz=0;1ll<<sz<=n;sz++);
			for(jj=0;jj<2;jj++)
			{
				for(i=0;i<sz2-sz+1;i++)
				{
					for(j=0;j<sz;j++)
					{
						if((m>>i+j&1)!=(n>>j&1))
						{
							break;
						}
					}
					if(j<sz)
					{
						continue;
					}
					for(j=0;j<sz2;j++)
					{
						if((j<i||j>=i+sz)&&!(m>>j&1))
						{
							break;
						}
					}
					if(j>=sz2)
					{
						break;
					}
				}
				if(i<sz2-sz+1)
				{
					break;
				}
				k=0;
				for(;n;n/=2)
				{
					k=k<<1|n&1;
				}
				n=k;
			}
			if(jj<2)
			{
				break;
			}
			if(!ii)
			{
				for(n/=2;n%2==0;n/=2);
			}
		}
		z=ii<2;
	}
	if(z)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}