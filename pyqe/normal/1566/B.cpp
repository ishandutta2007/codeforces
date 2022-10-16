#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n;

int main()
{
	long long t,rr,i,k,c,mn,mx,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		c=0;
		mn=inf;
		mx=-inf;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'0';
			if(!k)
			{
				c++;
				mn=min(mn,i);
				mx=i;
			}
		}
		if(!c)
		{
			z=0;
		}
		else if(mx-mn+1==c)
		{
			z=1;
		}
		else
		{
			z=2;
		}
		printf("%lld\n",z);
	}
}