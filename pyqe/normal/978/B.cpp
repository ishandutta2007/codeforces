#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,ln,z=0,c=0;
	string s;
	
	scanf("%lld",&ln);
	cin>>s;
	for(i=0;i<ln;i++)
	{
		if(s[i]=='x')
		{
			c++;
			if(c>=3)
			{
				z++;
			}
		}
		else
		{
			c=0;
		}
	}
	printf("%lld\n",z);
}