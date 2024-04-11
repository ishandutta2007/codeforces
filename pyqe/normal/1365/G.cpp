#include <bits/stdc++.h>

using namespace std;

const long long d=63;
long long n,nn=0,cn,pst[1069],ca[1069],wg[63],sq[1069];

long long qr()
{
	if(cn)
	{
		long long i,k;
		
		printf("? %lld",cn);
		for(i=1;i<=cn;i++)
		{
			printf(" %lld",ca[i]);
		}
		printf("\n");
		fflush(stdout);
		scanf("%lld",&k);
		return k;
	}
	else
	{
		return 0;
	}
}

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=1;nn<n;i++)
	{
		if(__builtin_popcount(i)<=8)
		{
			nn++;
			pst[i]=nn;
		}
	}
	for(i=0;i<10;i++)
	{
		cn=0;
		for(j=0;j<1ll<<10;j++)
		{
			if(pst[j]&&(j>>i&1))
			{
				cn++;
				ca[cn]=pst[j];
			}
		}
		k=qr();
		for(j=0;j<d;j++)
		{
			wg[j]|=(long long)(k>>j&1)<<i;
		}
	}
	for(j=0;j<d;j++)
	{
		if(__builtin_popcount(wg[j])>8)
		{
			wg[j]=-1;
		}
	}
	for(i=0;i<3;i++)
	{
		cn=0;
		for(j=0;j<1ll<<10;j++)
		{
			if(pst[j]&&!(__builtin_popcount(j)-1>>i&1))
			{
				cn++;
				ca[cn]=pst[j];
			}
		}
		k=qr();
		for(j=0;j<d;j++)
		{
			if(wg[j]>0&&(__builtin_popcount(wg[j])-1>>i&1)&&(k>>j&1))
			{
				wg[j]=-1;
			}
		}
	}
	for(i=0;i<d;i++)
	{
		if(wg[i])
		{
			for(j=1;j<=n;j++)
			{
				sq[j]|=(long long)(wg[i]==-1||j!=pst[wg[i]])<<i;
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