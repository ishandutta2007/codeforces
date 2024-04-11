#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,d,nn,a[100069],sq[100069];
bitset<100069> spc[10];
bitset<10> vtd;

int main()
{
	long long t,rr,i,j,mx;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		nn=0;
		for(i=0;i<10;i++)
		{
			spc[i][0]=1;
		}
		for(;n;n/=10)
		{
			nn++;
			a[nn]=n%10;
			for(i=0;i<10;i++)
			{
				spc[i][nn]=spc[i][nn-1];
				if(a[nn]>i)
				{
					spc[i][nn]=0;
				}
				else if(a[nn]<i)
				{
					spc[i][nn]=1;
				}
			}
		}
		vtd.reset();
		mx=-inf;
		bad=0;
		for(i=nn;i;i--)
		{
			for(j=0;j<10;j++)
			{
				if((d||vtd[j])&&(bad||j>=a[i])&&(bad||d-!vtd[j]||j>a[i]||spc[max(mx,j)][i-1]))
				{
					break;
				}
			}
			sq[i]=j;
			d-=!vtd[j];
			vtd[j]=1;
			mx=max(mx,j);
			bad|=j>a[i];
		}
		for(i=nn;i;i--)
		{
			printf("%lld",sq[i]);
		}
		printf("\n");
	}
}