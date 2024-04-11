#include <bits/stdc++.h>

using namespace std;

long long n,sm;
bool c0,c2;

int main()
{
	long long t,rr,i,k;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		c0=0;
		c2=0;
		sm=0;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'0';
			if(!k&&!c0)
			{
				c0=1;
			}
			else if(k%2==0)
			{
				c2=1;
			}
			sm=(sm+k)%3;
		}
		if(c0&&c2&&!sm)
		{
			printf("red\n");
		}
		else
		{
			printf("cyan\n");
		}
	}
}