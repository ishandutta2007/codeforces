#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> a[2],sq;

int main()
{
	long long i,ii;
	bool c=0;
	string s;
	
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[ii][i]=s[i-1]-'0';
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[0][i]!=a[1][i])
		{
			sq[i]=a[0][i]^c;
			c^=1;
		}
	}
	if(c)
	{
		printf("impossible\n");
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			printf("%lld",(long long)sq[i]);
		}
		printf("\n");
	}
}