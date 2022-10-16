#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069];

int main()
{
	long long t,rr,i,ii;
	bool bad;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf(" %c",&ch);
				a[ii][i]=ch-'0';
			}
		}
		bad=0;
		for(i=1;i<=n;i++)
		{
			bad|=a[0][i]&&a[1][i];
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}