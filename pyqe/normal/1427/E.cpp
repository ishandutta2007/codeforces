#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,ma=20,zs=0;
pair<long long,long long> sq[100069];
bitset<100069> spc;

void ad(bool ky,long long x,long long y)
{
	zs++;
	sq[zs]={x,y};
	spc[zs]=ky;
}

int main()
{
	long long i,j,k,l,w;
	
	scanf("%lld",&n);
	d=n;
	if(n&2)
	{
		ad(0,n,n);
		ad(0,n,n*2);
		d=n*3;
	}
	for(i=0;1ll<<i+1<=d;i++)
	{
		ad(0,d<<i,d<<i);
	}
	ad(0,d,d<<i);
	ad(1,d,d<<i);
	ad(1,d+(d<<i),d^d<<i);
	w=i+1;
	for(i=0;1ll<<i+2<=n;i++)
	{
		ad(0,1ll<<w+i,1ll<<w+i);
	}
	for(i=0;i<w-1;i++)
	{
		ad(0,n<<i,n<<i);
	}
	for(i=w-1;i+1;i--)
	{
		k=n;
		for(j=1;1ll<<j<=k;j++)
		{
			if(k>>j&1)
			{
				ad(1,k<<i,1ll<<i+j);
				k^=1ll<<j;
			}
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %c %lld\n",k,"+^"[spc[i]],l);
	}
}