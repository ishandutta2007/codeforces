#include <bits/stdc++.h>

using namespace std;

long long n,a[2][200069],fh[200069];

int main()
{
	long long t,rr,i,j,ii,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
			}
		}
		for(i=n;i;i--)
		{
			if(i==n||a[1][i]<a[0][i+1])
			{
				l=i;
			}
			fh[i]=l;
		}
		for(j=1,i=1;i<=n;i++)
		{
			for(;a[1][j]<a[0][i];j++);
			printf("%lld%c",a[1][j]-a[0][i]," \n"[i==n]);
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",a[1][fh[i]]-a[0][i]," \n"[i==n]);
		}
	}
}