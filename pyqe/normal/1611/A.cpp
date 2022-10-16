#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,z;
	bool bad;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		bad=0;
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'0';
			bad|=a[i]%2==0;
		}
		if(a[n]%2==0)
		{
			z=0;
		}
		else if(a[1]%2==0)
		{
			z=1;
		}
		else if(bad)
		{
			z=2;
		}
		else
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}