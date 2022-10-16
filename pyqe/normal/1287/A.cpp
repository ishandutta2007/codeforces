#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,c,mx;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		c=-1e18;
		mx=0;
		for(i=0;i<n;i++)
		{
			c++;
			if(s[i]=='A')
			{
				c=0;
			}
			mx=max(mx,c);
		}
		printf("%lld\n",mx);
	}
}