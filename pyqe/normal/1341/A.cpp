#include <bits/stdc++.h>

using namespace std;

long long n,m[2],d[2];

int main()
{
	long long t,rr,ii,z[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld%lld",m+ii,d+ii);
		}
		z[0]=(m[0]-d[0])*n;
		z[1]=(m[0]+d[0])*n;
		if(!(z[0]>m[1]+d[1]||z[1]<m[1]-d[1]))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}