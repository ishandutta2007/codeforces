#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long i,p,p2;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(p=1;p<=n&&a[p]<=d;p++);
	for(p2=n;p2&&a[p2]<=d;p2--);
	printf("%lld\n",n-max(p2-p+1,0ll));
}