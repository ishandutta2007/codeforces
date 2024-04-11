#include <bits/stdc++.h>

using namespace std;

long long n,d,z[100069];
bitset<100069> a;

int main()
{
	long long i,ls;
	string s;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<=n-d;i++)
	{
		cin>>s;
		a[i]=s[0]=='Y';
	}
	ls=d-1;
	for(i=1;i<d;i++)
	{
		z[i]=i-1;
	}
	for(i=d;i<=n;i++)
	{
		if(a[i-d])
		{
			z[i]=ls;
			ls=z[i-d+1];
		}
		else
		{
			z[i]=z[i-d+1];
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("A%c%c%c%c%c",(char)(z[i]/26/26/26%26)+'a',(char)(z[i]/26/26%26)+'a',(char)(z[i]/26%26)+'a',(char)(z[i]%26)+'a'," \n"[i==n]);
	}
}