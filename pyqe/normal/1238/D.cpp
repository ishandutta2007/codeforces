#include <bits/stdc++.h>

using namespace std;

long long ln;

int main()
{
	long long i,z,c=0;
	bool ft=1;
	string s;
	
	scanf("%lld",&ln);
	z=ln*(ln-1)/2;
	cin>>s;
	for(i=0;i<ln;i++)
	{
		c++;
		if(i==ln-1||s[i]!=s[i+1])
		{
			if(i<ln-1)
			{
				z-=c;
			}
			if(!ft)
			{
				z-=c-1;
			}
			ft=0;
			c=0;
		}
	}
	printf("%lld\n",z);
}