#include <bits/stdc++.h>

using namespace std;

long long n,ps[100069],inf=1e18;

int main()
{
	long long t,rr,i,k,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'0';
			ps[i]=ps[i-1]+k;
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			z=min(z,min(ps[i]+n-i-(ps[n]-ps[i]),i-ps[i]+ps[n]-ps[i]));
		}
		printf("%lld\n",z);
	}
}