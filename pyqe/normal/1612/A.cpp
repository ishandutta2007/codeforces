#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,x,y;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&x,&y);
		if(x%2==y%2)
		{
			printf("%lld %lld\n",x/2,(y+1)/2);
		}
		else
		{
			printf("-1 -1\n");
		}
	}
}