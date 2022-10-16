#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,a[200069];

int main()
{
	long long i,lb,rb,z;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'a';
	}
	for(lb=1;lb<n&&a[lb+1]==a[lb];lb++);
	for(rb=n;rb>1&&a[rb-1]==a[rb];rb--);
	if(lb==n)
	{
		z=n*(n+1)/2;
	}
	else if(a[1]==a[n])
	{
		z=(lb+1)*(n+1-rb+1)-(lb+1==rb);
	}
	else
	{
		z=lb+n+1-rb+1;
	}
	printf("%lld\n",z%dv);
}