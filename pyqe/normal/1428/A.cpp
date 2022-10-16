#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,y,x,y2,x2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&y,&x,&y2,&x2);
		printf("%lld\n",abs(y-y2)+abs(x-x2)+2*(y!=y2&&x!=x2));
	}
}