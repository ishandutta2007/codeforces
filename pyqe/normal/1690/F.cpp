#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[100069],pm[100069],ca[100069],faf[100069];
bitset<100069> vtd;

int main()
{
	long long t,rr,i,j,k,p,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'a';
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",pm+i);
		}
		z=1;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				nn=0;
				faf[0]=-1;
				for(p=i;!vtd[p];p=pm[p])
				{
					vtd[p]=1;
					nn++;
					ca[nn]=a[p];
					for(j=faf[nn-1];j+1&&ca[j+1]!=ca[nn];j=faf[j]);
					faf[nn]=j+1;
				}
				k=nn-faf[nn];
				if(nn%k)
				{
					k=nn;
				}
				z=z/__gcd(z,k)*k;
			}
		}
		printf("%lld\n",z);
	}
}