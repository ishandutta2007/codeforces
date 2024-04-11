#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200069],sm[200069];

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		sm[i%m]+=a[i];
		z+=sm[i%m];
		printf("%lld%c",z," \n"[i==n-1]);
	}
}