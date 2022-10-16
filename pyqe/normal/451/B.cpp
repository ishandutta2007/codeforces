#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,l=-1,d=-1,b=-1,m,i,n,p=-1,q;
	bool g=true;
	
	scanf("%lld",&n);
	q=n;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k>l&&b==-1)
		{
			d=l;
		}
		else if(k<l&&b==-1)
		{
			b=l;
			p=i;
		}
		else if(k>l&&q==n)
		{
			if(l<d||k<b)
			{
				g=false;
			}
			q=i;
		}
		else if(k<l&&q!=n)
		{
			g=false;
		}
		l=k;
	}
	if(q==n&&k<d)
	{
		g=false;
	}
	if(g)
	{
		if(p==-1)
		{
			printf("yes\n1 1\n");
		}
		else
		{
			printf("yes\n%lld %lld\n",p,q);
		}
	}
	else
	{
		printf("no\n");
	}
}