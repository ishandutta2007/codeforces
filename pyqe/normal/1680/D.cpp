#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,d,nn=0,sma[3069],mna[3069],mxa[3069],ps[3069];

int main()
{
	long long i,j,k,sm=0,mn=0,mx=0,w,z=-inf;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n+1;i++)
	{
		k=0;
		if(i<=n)
		{
			scanf("%lld",&k);
		}
		if(k)
		{
			sm+=k;
			mn=min(mn,sm);
			mx=max(mx,sm);
		}
		else
		{
			nn++;
			sma[nn]=sm;
			mna[nn]=mn;
			mxa[nn]=mx;
			ps[nn]=ps[nn-1]+sma[nn];
			sm=0;
			mn=0;
			mx=0;
		}
	}
	if(abs(ps[nn])>d*(nn-1))
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=nn;i++)
	{
		mn=max(ps[i-1]-d*(i-1),-(ps[nn]-ps[i-1])-d*(nn-i))+mna[i];
		for(j=1;j<=nn;j++)
		{
			mx=min(ps[j-1]+d*(j-1),-(ps[nn]-ps[j-1])+d*(nn-j))+mxa[j];
			w=mx-mn+1;
			if(i<=j)
			{
				w=min(w,mxa[j]-mna[i]+ps[j-1]-ps[i-1]+d*(j-i)+1);
			}
			else
			{
				w=min(w,mxa[j]-mna[i]+ps[j-1]-ps[i-1]+d*(i-j)+1);
			}
			z=max(z,w);
		}
	}
	printf("%lld\n",z);
}