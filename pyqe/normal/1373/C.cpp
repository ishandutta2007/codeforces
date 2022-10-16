#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long t,rr,i,sm,mn,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		sm=0;
		mn=0;
		z=n;
		for(i=1;i<=n;i++)
		{
			sm+=(s[i-1]=='+')*2-1;
			if(sm<mn)
			{
				z+=i;
				mn=sm;
			}
		}
		printf("%lld\n",z);
	}
}