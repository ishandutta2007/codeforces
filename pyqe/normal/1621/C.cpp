#include <bits/stdc++.h>

using namespace std;

long long n,nn,ca[10069],sq[10069];
bitset<10069> vtd;

inline long long qr(long long x)
{
	long long k;
	
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

int main()
{
	long long t,rr,i,j,k,l,p,e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				nn=0;
				for(;1;)
				{
					k=qr(i);
					if(vtd[k])
					{
						break;
					}
					vtd[k]=1;
					nn++;
					ca[nn]=k;
					if(k==i)
					{
						e=nn;
					}
				}
				for(p=i,j=1;j<=nn;j++,p=l)
				{
					l=ca[(e+j-1)%nn+1];
					sq[p]=l;
				}
			}
		}
		printf("!");
		for(i=1;i<=n;i++)
		{
			printf(" %lld",sq[i]);
		}
		printf("\n");
		fflush(stdout);
	}
}