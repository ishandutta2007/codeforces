#include <bits/stdc++.h>

using namespace std;

long long n,d;

inline bool ip(long long x)
{
	long long i;
	
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	long long t,rr,w,c,w2,c2;
	bool z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(c=0,w=n;w%d==0;w/=d,c++);
		for(c2=0,w2=d;w>1&&w2%w==0;w2/=w,c2++);
		if(c<=1)
		{
			z=0;
		}
		else if(!ip(w))
		{
			z=1;
		}
		else if(c==2)
		{
			z=0;
		}
		else if(ip(d))
		{
			z=0;
		}
		else if(w2>1)
		{
			z=1;
		}
		else if(c==3&&c2==2)
		{
			z=0;
		}
		else
		{
			z=1;
		}
		if(z)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}