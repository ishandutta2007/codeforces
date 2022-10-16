#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n<4)
		{
			printf("-1\n");
			continue;
		}
		c=0;
		for(i=(n-1)/2*2+1;i>0;i-=2)
		{
			c++;
			printf("%lld ",i);
		}
		for(i=2;i<=n;i+=2)
		{
			c++;
			printf("%lld%c",i+2*(i==2)-2*(i==4)," \n"[c==n]);
		}
	}
}