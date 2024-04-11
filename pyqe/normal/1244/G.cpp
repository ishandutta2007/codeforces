#include <bits/stdc++.h>

using namespace std;

long long n,d,pst[1000069],z[2][1000069];
bitset<1000069> vtd[2];

int main()
{
	long long i,ii,j,ttl,k;
	
	scanf("%lld%lld",&n,&d);
	ttl=d-n*(n+1)/2;
	for(i=0;i<n;i++)
	{
		pst[i]=i*2;
	}
	if(ttl<0)
	{
		printf("-1\n");
		return 0;
	}
	for(i=n-1;i>=0;i--)
	{
		k=min(ttl*2,n+i-pst[i]);
		pst[i]+=k;
		ttl-=k/2;
	}
	for(i=0;i<n;i++)
	{
		z[pst[i]%2][i]=pst[i]/2+1;
		vtd[pst[i]%2][pst[i]/2+1]=1;
	}
	printf("%lld\n",d-ttl);
	for(ii=0;ii<2;ii++)
	{
		for(j=1,i=0;i<n;i++)
		{
			if(!z[ii][i])
			{
				for(;j<=n&&vtd[ii][j];j++);
				z[ii][i]=j;
				vtd[ii][j]=1;
			}
			printf("%lld%c",z[ii][i]," \n"[i==n-1]);
		}
	}
}