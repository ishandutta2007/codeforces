#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[2][50069],inf=1e18;
bitset<400069> a;

int main()
{
	long long t,rr,i,j,ii,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<n;i++)
			{
				fq[ii][i]=0;
			}
			swap(n,m);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf(" %ch",&ch);
				a[i*m+j]=ch=='.';
				fq[0][i]+=a[i*m+j];
				fq[1][j]+=a[i*m+j];
			}
		}
		z=inf;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				z=min(z,fq[0][i]+fq[1][j]-a[i*m+j]);
			}
		}
		printf("%lld\n",z);
	}
}