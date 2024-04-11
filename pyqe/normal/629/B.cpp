#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn[2],ln=366,sq[2][100069],inf=1e18;
pair<long long,long long> a[2][200069];

int main()
{
	long long i,j,ii,k,l,e,sm,z=-inf;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c%lld%lld",&ch,&k,&l);
		e=ch=='M';
		nn[e]+=2;
		a[e][nn[e]-1]={k,1};
		a[e][nn[e]]={l+1,-1};
	}
	for(ii=0;ii<2;ii++)
	{
		sort(a[ii]+1,a[ii]+nn[ii]+1);
		sm=0;
		for(j=1,i=1;i<=ln;i++)
		{
			for(;j<=nn[ii]&&a[ii][j].fr<=i;j++)
			{
				sm+=a[ii][j].sc;
			}
			sq[ii][i]=sm;
		}
	}
	for(i=1;i<=ln;i++)
	{
		z=max(z,min(sq[0][i],sq[1][i])*2);
	}
	printf("%lld\n",z);
}