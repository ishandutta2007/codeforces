#include <bits/stdc++.h>

using namespace std;

long long n,d,d2,sq[100069];
bitset<100069> vtd;

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&d2);
		if(n+1-d-(d2>d)<n/2||d2-(d<d2)<n/2)
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		sq[1]=d;
		vtd[d]=1;
		sq[n/2+1]=d2;
		vtd[d2]=1;
		for(j=n,i=2;i<=n/2;i++)
		{
			for(;vtd[j];j--);
			sq[i]=j;
			vtd[j]=1;
		}
		for(j=1,i=n/2+2;i<=n;i++)
		{
			for(;vtd[j];j++);
			sq[i]=j;
			vtd[j]=1;
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}