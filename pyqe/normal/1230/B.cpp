#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

int main()
{
	long long i,k;
	string s;
	
	scanf("%lld%lld",&n,&d);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(i=1;i<=n;i++)
	{
		k=i==1&&i<n;
		if(d&&a[i]>k)
		{
			a[i]=k;
			d--;
		}
		printf("%lld",a[i]);
	}
	printf("\n");
}