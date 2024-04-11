#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long y,x,y2,x2,y3,x3;
	
	scanf("%lld%lld%lld%lld",&y,&x,&y2,&x2);
	if(y-x>=y2-x2)
	{
		y3=max(y-((y-x)-(y2-x2)),0ll);
		x3=x;
	}
	else
	{
		y3=y;
		x3=max(x-((y2-x2)-(y-x)),0ll);
	}
	if(y-y3+x-x3<=max(y2-y3,x2-x3))
	{
		printf("Polycarp\n");
	}
	else
	{
		printf("Vasiliy\n");
	}
}