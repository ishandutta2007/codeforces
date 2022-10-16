#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long b=-1,d=-1,c,e,n,i,k,z;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(b==-1||k>b)
		{
			b=k;
			c=1;
		}
		else if(k==b)
		{
			c++;
		}
		if(d==-1||k<d)
		{
			d=k;
			e=1;
		}
		else if(k==d)
		{
			e++;
		}
	}
	if(b==d)
	{
		z=c*(c-1)/2;
	}
	else
	{
		z=c*e;
	}
	printf("%lld %lld\n",b-d,z);
}