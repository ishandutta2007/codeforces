#include <bits/stdc++.h>

using namespace std;

long long n,d,ma=160,a[169],sq[169],inf=1e18;

int main()
{
	long long t,rr,i,j,r,k,w,sm;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		sq[ma]=inf;
		for(i=0;i<10;i++)
		{
			sm=n;
			for(j=0;j<=d;j++)
			{
				sm-=(i+j)%10;
			}
			for(j=0;1;j++)
			{
				w=1-j*9;
				k=sm-w*max(i+d-9,0ll);
				if(k<=-w*(d+1))
				{
					break;
				}
				if(k>=0&&k%(d+1)==0)
				{
					k/=d+1;
					a[0]=i;
					for(r=1;r<=ma;r++)
					{
						w=min(9ll-(r==j+1),k);
						a[r]=w;
						k-=w;
					}
					for(r=ma;r+1;r--)
					{
						if(a[r]<sq[r])
						{
							r=-69;
							break;
						}
						else if(a[r]>sq[r])
						{
							break;
						}
					}
					if(r==-69)
					{
						for(r=0;r<=ma;r++)
						{
							sq[r]=a[r];
						}
					}
				}
			}
		}
		if(sq[ma]==inf)
		{
			printf("-1\n");
		}
		else
		{
			bad=0;
			for(i=ma;i+1;i--)
			{
				if(sq[i]||!i)
				{
					bad=1;
				}
				if(bad)
				{
					printf("%lld",sq[i]);
				}
			}
			printf("\n");
		}
	}
}