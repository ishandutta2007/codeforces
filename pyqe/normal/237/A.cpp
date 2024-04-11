#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,h,m,k=-1,l=-1,c=0,b=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&h,&m);
		if(h==k&&m==l)
		{
			c++;
		}
		else
		{
			if(c>b)
			{
				b=c;
			}
			c=1;
		}
		k=h;
		l=m;
	}
	if(c>b)
	{
		b=c;
	}
	printf("%lld\n",b);
}