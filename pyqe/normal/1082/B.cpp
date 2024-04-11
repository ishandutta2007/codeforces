#include <bits/stdc++.h>

using namespace std;

long long n,dp[2][100069],fq=0,inf=1e18;
bitset<100069> a;

int main()
{
	long long i,ii,u,z=-inf;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]=='G';
		fq+=a[i];
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			dp[ii][i]=(dp[ii][i-u]+1)*a[i];
		}
	}
	for(i=1;i<=n;i++)
	{
		z=max(z,min(dp[0][i-1]+1+dp[1][i+1],fq));
	}
	printf("%lld\n",z);
}