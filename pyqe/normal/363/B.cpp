#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,k,z=0,b=-1,d,i,p;
	
	scanf("%lld%lld",&n,&m);
	long long aa[n+1];
	for(i=0;i<=n;i++)
	{
		if(i>0)
		{
			scanf("%lld",&k);
			z+=k;
		}
		aa[i]=z;
	}
	for(i=m;i<=n;i++)
	{
		d=aa[i]-aa[i-m];
		if(b==-1||d<b)
		{
			b=d;
			p=i-m+1;
		}
	}
	printf("%lld\n",p);
}