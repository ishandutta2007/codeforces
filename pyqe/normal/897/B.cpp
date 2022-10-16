#include <bits/stdc++.h>

using namespace std;

long long n,dv;

int main()
{
	long long i,k,w,z=0;
	
	scanf("%lld%lld",&n,&dv);
	for(i=1;i<=n;i++)
	{
		w=i;
		for(k=i;k;k/=10)
		{
			w=w*10+k%10;
		}
		z=(z+w)%dv;
	}
	printf("%lld\n",z);
}