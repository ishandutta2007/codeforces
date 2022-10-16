#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,c=0,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]=='(';
		if(k)
		{
			c++;
		}
		else
		{
			z+=!!c*2;
			c=max(c-1,0ll);
		}
	}
	printf("%lld\n",z);
}