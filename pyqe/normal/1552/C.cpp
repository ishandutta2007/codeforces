#include <bits/stdc++.h>

using namespace std;

long long n,d,a[169][2];
bitset<269> vtd;

int main()
{
	long long t,rr,i,j,ii,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		vtd.reset();
		for(i=1;i<=d;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				scanf("%lld",&a[i][ii]);
				vtd[a[i][ii]]=1;
			}
			if(a[i][0]>a[i][1])
			{
				swap(a[i][0],a[i][1]);
			}
		}
		c=0;
		for(i=1;i<=n*2;i++)
		{
			if(!vtd[i])
			{
				c++;
				a[d+(c-1)%(n-d)+1][c>n-d]=i;
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i][0]>a[j][0])
				{
					swap(i,j);
				}
				z+=a[j][0]<a[i][1]&&a[i][1]<a[j][1];
				if(i>j)
				{
					swap(i,j);
				}
			}
		}
		printf("%lld\n",z);
	}
}