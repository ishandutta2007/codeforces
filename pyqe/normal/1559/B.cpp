#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

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
			a[i]=(ch=='R')-(ch=='?');
		}
		a[0]=-1;
		a[n+1]=0;
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(i=1+(n-1)*ii;i&&i<=n;i+=u)
			{
				if(a[i]==-1&&a[i-u]+1)
				{
					a[i]=!a[i-u];
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%c","BR"[a[i]]);
		}
		printf("\n");
	}
}