#include <bits/stdc++.h>

using namespace std;

long long n,m,inf=1e18;
bitset<500069> a[2];

int main()
{
	long long i,ii,k,l=0,w,z;
	bool bad=1;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[ii][i]=s[i-1]-'a';
		}
	}
	z=n;
	m--;
	for(i=1;i<=n;i++)
	{
		if(!bad)
		{
			k=l;
			for(ii=0;ii<2;ii++)
			{
				k+=a[ii][i]==ii;
			}
			w=min(k,m);
			z+=(n-i+1)*w;
			m-=w;
			k=min(k+l,inf);
			l=k;
		}
		else if(a[0][i]!=a[1][i])
		{
			bad=0;
			z+=(n-i+1)*!!m;
			m-=!!m;
		}
	}
	printf("%lld\n",z);
}