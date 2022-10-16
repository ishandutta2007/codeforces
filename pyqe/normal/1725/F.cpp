#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=1e9;
long long n,nn,sq[100069];
pair<long long,long long> a[100069],as[400069];

inline void ad(long long x,long long y)
{
	nn++;
	as[nn]={x,1};
	nn++;
	as[nn]={y+1,-1};
}

int main()
{
	long long t,rr,i,j,k,l,c;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={k,l};
	}
	for(i=0;1ll<<i<=ma;i++)
	{
		nn=0;
		for(j=1;j<=n;j++)
		{
			k=a[j].fr;
			l=a[j].sc;
			if((l-k+1)>=1ll<<i)
			{
				ad(0,(1ll<<i)-1);
			}
			else
			{
				k%=1ll<<i;
				l%=1ll<<i;
				if(k<=l)
				{
					ad(k,l);
				}
				else
				{
					ad(k,(1ll<<i)-1);
					ad(0,l);
				}
			}
		}
		sort(as+1,as+nn+1);
		c=0;
		for(j=1;j<=nn;j++)
		{
			c+=as[j].sc;
			sq[i]=max(sq[i],c);
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		for(i=0;!(k>>i&1);i++);
		printf("%lld\n",sq[i]);
	}
}