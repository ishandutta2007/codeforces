#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,z;
	string s;
	bool bad=0,bad2=0;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=1;i<=n;i++)
	{
		bad|=a[i]!=a[n+1-i];
		bad2|=a[i]!=a[1];
	}
	if(bad)
	{
		z=n;
	}
	else if(bad2)
	{
		z=n-1;
	}
	else
	{
		z=0;
	}
	printf("%lld\n",z);
}