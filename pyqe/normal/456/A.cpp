#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a1=-1,a2=-1,b1=-1,b2=-1,n,k1,k2,i;
	bool g=true;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k1,&k2);
		if(a1!=-1&&b2!=-1&&((k1<a1&&k2>a2)||(k1>a1&&k2<a2)||(k1<b1&&k2>b2)||(k1>b1&&k2<b2)))
		{
			g=false;
		}
		if(a1==-1||k1<a1&&k2<a2)
		{
			a1=k1;
			a2=k2;
		}
		if(b1==-1||k1>b1&&k2>b2)
		{
			b1=k1;
			b2=k2;
		}
	}
	if(g)
	{
		printf("Poor Alex\n");
	}
	else
	{
		printf("Happy Alex\n");
	}
}