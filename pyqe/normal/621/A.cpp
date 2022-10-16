#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,b=-1,z=0,n,i;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		z+=k;
		if(k%2==1&&(b==-1||k<b))
		{
			b=k;
		}
	}
	if(z%2==1)
	{
		z-=b;
	}
	printf("%lld\n",z);
}