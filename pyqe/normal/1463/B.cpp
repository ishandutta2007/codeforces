#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sm[2];

int main()
{
	long long t,rr,i,ii,e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			sm[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			sm[i%2]+=a[i]-1;
		}
		e=sm[1]<sm[0];
		for(i=1;i<=n;i++)
		{
			if(i%2==e)
			{
				a[i]=1;
			}
			printf("%lld%c",a[i]," \n"[i==n]);
		}
	}
}