#include <bits/stdc++.h>

using namespace std;

long long n[2],ps[30];

int main()
{
	long long t,rr,i,ii,u,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<30;i++)
		{
			ps[i]=0;
		}
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",n+ii);
			u=!ii*2-1;
			for(i=0,k=n[ii];k;k/=2,i++)
			{
				ps[i]+=k%2*u;
			}
		}
		for(i=0;i<30;i++)
		{
			if(i)
			{
				ps[i]+=ps[i-1];
			}
			if(ps[i]<0)
			{
				break;
			}
		}
		if(i>=30&&n[0]<=n[1])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}