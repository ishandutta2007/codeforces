#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long x1,y1,x2,y2,d;
	
	scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
	if(x1==x2)
	{
		d=abs(y1-y2);
		printf("%lld %lld %lld %lld\n",x1+d,y1,x2+d,y2);
	}
	else if(y1==y2)
	{
		d=abs(x1-x2);
		printf("%lld %lld %lld %lld\n",x1,y1+d,x2,y2+d);
	}
	else if(abs(x1-x2)==abs(y1-y2))
	{
		d=abs(x1-x2);
		printf("%lld %lld %lld %lld\n",x1,y2,x2,y1);
	}
	else
	{
		printf("-1\n");
	}
}