#include <bits/stdc++.h>

using namespace std;

struct line
{
	long long a,b,c;
}
ln,ln2;

int main()
{
	long long y,x,lh,rh,md,dtr;
	double yi,z;
	
	scanf("%lld%lld",&x,&y);
	if(x<y)
	{
		printf("-1\n");
		return 0;
	}
	ln.a=-y;
	ln.b=x;
	ln.c=0;
	ln2.a=1;
	ln2.b=1;
	lh=1;
	rh=1e9;
	for(;lh<=rh;)
	{
		md=(lh+rh)/2;
		ln2.c=-md*2;
		dtr=ln.a*ln2.b-ln2.a*ln.b;
		yi=(double)(ln.c*ln2.a-ln2.c*ln.a)/dtr;
		if(yi>1)
		{
			rh=md-1;
		}
		else
		{
			z=(double)y/yi;
			lh=md+1;
		}
	}
	printf("%.12lf\n",z);
}