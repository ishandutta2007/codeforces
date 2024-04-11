#include <bits/stdc++.h>

using namespace std;

long long n,m,ps[1000069],c;

int main()
{
	long long i,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+s[i-1]-'0';
	}
	cin>>s;
	m=s.length();
	for(i=0;i<m;i++)
	{
		c+=s[i]-'0';
	}
	for(i=m;i<=n;i++)
	{
		if((ps[i]-ps[i-m])%2==c%2)
		{
			z++;
		}
	}
	printf("%lld\n",z);
}