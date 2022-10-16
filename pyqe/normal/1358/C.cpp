#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,y,x,y2,x2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&y,&x,&y2,&x2);
		y=y2-y+1;
		x=x2-x+1;
		if(y>x)
		{
			swap(y,x);
		}
		printf("%lld\n",(y-1)*(x-1)+1);
	}
}