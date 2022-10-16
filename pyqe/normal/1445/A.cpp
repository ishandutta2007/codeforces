#include <bits/stdc++.h>

using namespace std;

long long n,d,a[2][100069];

int main()
{
	long long t,rr,i,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
			}
		}
		sort(a[0]+1,a[0]+n+1);
		sort(a[1]+1,a[1]+n+1,greater<long long>());
		for(i=1;i<=n;i++)
		{
			if(a[0][i]+a[1][i]>d)
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}