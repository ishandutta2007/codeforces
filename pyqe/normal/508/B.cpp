#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long i;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(i=1;i<=n&&a[n]%2;i++)
	{
		if(a[i]%2==0&&a[i]<a[n])
		{
			swap(a[i],a[n]);
		}
	}
	for(i=n;i&&a[n]%2;i--)
	{
		if(a[i]%2==0&&a[i]>a[n])
		{
			swap(a[i],a[n]);
		}
	}
	if(a[n]%2)
	{
		printf("-1\n");
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			printf("%lld",a[i]);
		}
		printf("\n");
	}
}