#include <bits/stdc++.h>

using namespace std;

long long n,fh[2][300069];
bitset<300069> a;

int main()
{
	long long t,rr,i,ii,u;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch=='R'^i%2==0;
		}
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			fh[ii][0]=1;
			fh[ii][n+1]=n;
			for(i=1+(n-1)*ii;i&&i<=n;i+=u)
			{
				if(a[i]==a[i-u])
				{
					fh[ii][i]=fh[ii][i-u];
				}
				else
				{
					fh[ii][i]=i;
				}
			}
		}
		for(i=0;i<=n;i++)
		{
			printf("%lld%c",(fh[1][i+1]-i)*(a[i+1]^i%2)+(i+1-fh[0][i])*(a[i]^i%2)+1," \n"[i==n]);
		}
	}
}