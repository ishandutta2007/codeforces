#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,ml=1,z;
	string s;
	
	cin>>s;
	n=s.length();
	z=(1ll<<n)-1;
	for(i=n;i;i--)
	{
		k=s[i-1]=='7';
		z+=k*ml;
		ml*=2;
	}
	printf("%lld\n",z);
}