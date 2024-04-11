#include <bits/stdc++.h>

using namespace std;

long long n,d,a[26];

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long i,mx=0,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	scanf("%lld",&d);
	for(i=0;i<26;i++)
	{
		scanf("%lld",a+i);
		mx=max(mx,a[i]);
	}
	for(i=1;i<=n;i++)
	{
		z+=a[s[i-1]-'a']*i;
	}
	z+=mx*(tri(n+d)-tri(n));
	printf("%lld\n",z);
}