#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,y,x,y2,x2,y3,x3;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&y,&x,&y2,&x2,&y3,&x3);
		printf("%lld\n",abs(y-y2)+abs(x-x2)+2*((y==y2&&y2==y3&&min(x,x2)<x3&&x3<max(x,x2))||(x==x2&&x2==x3&&min(y,y2)<y3&&y3<max(y,y2))));
	}
}