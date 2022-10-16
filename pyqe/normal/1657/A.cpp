#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,x,y,w,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&x,&y);
		w=x*x+y*y;
		for(i=0;(i+1)*(i+1)<=w;i++);
		if(!x&&!y)
		{
			z=0;
		}
		else if(i*i==w)
		{
			z=1;
		}
		else
		{
			z=2;
		}
		printf("%lld\n",z);
	}
}