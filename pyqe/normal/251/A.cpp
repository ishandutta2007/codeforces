#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long i,j,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(j=1,i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(;a[j]<a[i]-d;j++);
		z+=(i-j)*(i-j-1)/2;
	}
	printf("%lld\n",z);
}