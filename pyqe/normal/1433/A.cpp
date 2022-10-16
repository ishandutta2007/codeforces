#include <bits/stdc++.h>

using namespace std;

long long n;

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long t,rr,k;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		k=s[0]-'0';
		printf("%lld\n",tri(4)*(k-1)+tri(n));
	}
}