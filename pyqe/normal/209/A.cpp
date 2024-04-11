#include <bits/stdc++.h>

using namespace std;

long long n,dv=1e9+7;

int main()
{
	long long i,k=1,l=0,tmp,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		tmp=(k+l)%dv;
		l=k;
		k=tmp;
		z=(z+tmp)%dv;
	}
	printf("%lld\n",z);
}