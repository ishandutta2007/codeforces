#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> a;

int main()
{
	long long i,z;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]=='R';
	}
	z=n;
	for(i=1;i<n;i++)
	{
		if(a[i]^a[i+1])
		{
			z--;
			i++;
		}
	}
	printf("%lld\n",z);
}