#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];
bitset<1000069> a[2];

int main()
{
	long long i,ii,sm=0,mn=0,mx=0;
	string s;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[ii][i]=s[i-1]-'0';
			fq[ii]+=a[ii][i];
		}
	}
	if(fq[0]!=fq[1])
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(a[0][i]!=a[1][i])
		{
			sm+=a[0][i]*2-1;
			mn=min(mn,sm);
			mx=max(mx,sm);
		}
	}
	printf("%lld\n",mx-mn);
}