#include <bits/stdc++.h>

using namespace std;

long long n,a[3][100069],sq[100069];

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<3;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%lld",&a[i][j]);
				sq[j]=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<3;j++)
			{
				if(a[j][i]!=sq[(i+n-2)%n+1]&&a[j][i]!=sq[i%n+1])
				{
					break;
				}
			}
			sq[i]=a[j][i];
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}