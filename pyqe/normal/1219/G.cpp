#include <bits/stdc++.h>

using namespace std;

long long n,m,bs[4],sm[100069];

int main()
{
	long long i,j,r,rr,ii,i2,j2,mx=-1e18,ttl,c,k,z;
	
	scanf("%lld%lld",&n,&m);
	long long aa[n+1][m+1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&aa[i][j]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		long long a[n+1][m+1];
		for(j=1;j<=m;j++)
		{
			sm[j]=0;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				i2=i;
				j2=j;
				if(ii)
				{
					swap(i2,j2);
				}
				a[i][j]=aa[i2][j2];
				sm[j]+=a[i][j];
			}
		}
		for(rr=0;rr<=n*(n<=m);rr++)
		{
			for(r=rr+!!rr;r<=n;r++)
			{
				c=4-!!rr-!!r;
				for(i=0;i<c;i++)
				{
					bs[i]=-1e18;
				}
				ttl=0;
				for(j=1;j<=m;j++)
				{
					ttl+=a[rr][j]*!!rr+a[r][j]*!!r;
					z=sm[j]-a[rr][j]*!!rr-a[r][j]*!!r;
					for(k=0;k<c&&bs[k]>z;k++);
					for(i=c-1;i>k;i--)
					{
						bs[i]=bs[i-1];
					}
					bs[k]=z;
				}
				for(i=0;i<c;i++)
				{
					ttl+=max(bs[i],0ll);
				}
				mx=max(mx,ttl);
			}
		}
		swap(n,m);
	}
	printf("%lld\n",mx);
}