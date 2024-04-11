#include <bits/stdc++.h>

using namespace std;

long long n,d,d2;
bitset<300069> a;

int main()
{
	long long i,c=0,z;
	string s;
	
	scanf("%lld%lld%lld",&n,&d,&d2);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(i=1;i<=n;i++)
	{
		c+=!a[i]&&(i==n||a[i+1]);
	}
	z=min(c*d2,max(c-1,0ll)*d+d2);
	printf("%lld\n",z);
}