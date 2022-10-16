#include <bits/stdc++.h>

using namespace std;

long long n,a[569],od[569];

int main()
{
	long long i,j,p;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			p=i+1-j;
			for(od[p]++;a[od[p]]<p;od[p]++);
			printf("%lld%c",a[od[p]]," \n"[j==i]);
		}
	}
}