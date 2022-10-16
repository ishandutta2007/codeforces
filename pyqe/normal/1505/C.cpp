#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'A';
	}
	for(i=3;i<=n;i++)
	{
		if(a[i]!=(a[i-1]+a[i-2])%26)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}