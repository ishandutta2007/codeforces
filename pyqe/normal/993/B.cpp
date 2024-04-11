#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][1069][2],sq[2][1069],z=0;

void ad(long long &x,long long w)
{
	if(!x||x==w)
	{
		x=w;
	}
	else
	{
		x=-1;
	}
}

int main()
{
	long long i,j,ii,jj,k;
	
	scanf("%lld%lld",n,n+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n[ii];i++)
		{
			for(jj=0;jj<2;jj++)
			{
				scanf("%lld",&a[ii][i][jj]);
			}
		}
	}
	for(i=1;i<=n[0];i++)
	{
		for(j=1;j<=n[1];j++)
		{
			k=0;
			for(ii=0;ii<2;ii++)
			{
				for(jj=0;jj<2;jj++)
				{
					if(a[0][i][ii]==a[1][j][jj])
					{
						ad(k,a[0][i][ii]);
					}
				}
			}
			if(k>0)
			{
				ad(z,k);
				for(ii=0;ii<2;ii++)
				{
					ad(sq[ii][i],k);
					if(sq[ii][i]==-1)
					{
						printf("-1\n");
						return 0;
					}
					swap(i,j);
				}
			}
		}
	}
	printf("%lld\n",z+(z==-1));
}