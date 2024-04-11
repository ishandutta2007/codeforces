#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dp[2][100069];

int main()
{
	long long i,ii,u,c,p,w[2],z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		c=-1;
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			c++;
			dp[ii][i]=max(dp[ii][i-u],c);
			c*=!(i==1||i==n||(a[i]<a[i-1])==(a[i]<a[i+1]));
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>max(a[i-1],a[i+1]))
		{
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				for(w[ii]=0,p=i;p+u&&p+u<=n&&a[p+u]<a[p];p+=u,w[ii]++);
			}
			if(w[0]>w[1])
			{
				swap(w[0],w[1]);
			}
			z+=w[1]>max(dp[0][i-1],dp[1][i+1])&&w[0]>(w[1]-1)/2*2+1;
		}
	}
	printf("%lld\n",z);
}