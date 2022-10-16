#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069];

int main()
{
	long long t,rr,i,ii;
	bool bad,bad2;
	
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
		bad=1;
		bad2=1;
		for(i=1;i<=n;i++)
		{
			if((a[1][i]>a[0][i]&&bad)||(a[1][i]<a[0][i]&&bad2))
			{
				i=-1;
				break;
			}
			bad&=a[0][i]!=1;
			bad2&=a[0][i]!=-1;
		}
		if(i!=-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}