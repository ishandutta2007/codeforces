#include <bits/stdc++.h>

using namespace std;

long long n,m[2],d[2];

int main()
{
	long long t,rr,ii,jj;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld",&n,m,m+1,d,d+1);
		for(ii=0;ii<2;ii++)
		{
			if(d[ii]>min(m[0],m[1])+abs(m[0]-m[1])/2)
			{
				break;
			}
			for(jj=0;jj<2;jj++)
			{
				m[jj]=n-m[jj];
			}
		}
		if(ii>=2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}