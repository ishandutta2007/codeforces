#include <bits/stdc++.h>

using namespace std;

const long long d=10;
long long n,a[100069],a2[100069],sq[100069];

int main()
{
	long long t,rr,i;
	bool bad;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
		}
		if(a[1]<9)
		{
			a2[0]=0;
			for(i=1;i<=n;i++)
			{
				a2[i]=9;
			}
		}
		else
		{
			for(i=0;i<=n;i++)
			{
				a2[i]=1;
			}
		}
		bad=0;
		for(i=n;i;i--)
		{
			sq[i]=(a2[i]+d-a[i]-bad)%d;
			bad=a2[i]<a[i]+bad;
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld",sq[i]);
		}
		printf("\n");
	}
}