#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,l,c=0,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]=='P';
		if((i-1&&k!=l)||c==5)
		{
			z++;
			c=0;
		}
		c++;
		l=k;
	}
	z+=!!c;
	printf("%lld\n",z);
}