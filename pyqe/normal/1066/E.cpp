#include <bits/stdc++.h>

using namespace std;

long long n,m,pwk,dv=998244353;
bitset<200069> a;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long i,k,sm=0,z=0;
	string s;
	
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	cin>>s;
	for(i=1;i<=m;i++)
	{
		k=s[i-1]-'0';
		sm+=k;
		if(m-i<n)
		{
			z=(z+sm*pw(2,m-i)*a[n-(m-i)])%dv;
		}
	}
	printf("%lld\n",z);
}