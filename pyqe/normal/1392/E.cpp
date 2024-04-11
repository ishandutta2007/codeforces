#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,j,k,y,x;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lld%c",(1ll<<i+j)*(i%2)," \n"[j==n-1]);
		}
	}
	fflush(stdout);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		y=0;
		x=-1;
		for(i=0;i<n*2-1;i++)
		{
			if(k%2^y%2)
			{
				y++;
			}
			else
			{
				x++;
			}
			k>>=1;
			printf("%lld %lld\n",y+1,x+1);
			fflush(stdout);
		}
	}
}