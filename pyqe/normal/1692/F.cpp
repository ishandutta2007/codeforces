#include <bits/stdc++.h>

using namespace std;

const long long mm=10;
long long n,nn,a[200069],fq[mm],ex[200069];

int main()
{
	long long t,rr,i,j,r;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<mm;i++)
		{
			fq[i]=0;
		}
		nn=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			a[i]%=10;
			if(fq[a[i]]<3)
			{
				fq[a[i]]++;
				nn++;
				ex[nn]=i;
			}
		}
		bad=0;
		for(i=1;i<=nn;i++)
		{
			for(j=i+1;j<=nn;j++)
			{
				for(r=j+1;r<=nn;r++)
				{
					bad|=(a[ex[i]]+a[ex[j]]+a[ex[r]])%10==3;
				}
			}
		}
		if(bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}