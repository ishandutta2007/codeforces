#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dv=1e9+7;

long long tri(long long x)
{
	return x*(x+1)/2%dv;
}

int main()
{
	long long i,ml=1,sm=0,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(i=n;i;i--)
	{
		z=(z+a[i]*(sm+tri(i-1)*ml%dv))%dv;
		sm=(sm+ml*(n+1-i))%dv;
		ml=ml*10%dv;
	}
	printf("%lld\n",z);
}