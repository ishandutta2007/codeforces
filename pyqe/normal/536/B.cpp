#include <bits/stdc++.h>

using namespace std;

long long d,n,m,dv=1e9+7,a[1000069];
bitset<1000069> spc;

int main()
{
	long long i,k,l=-1e18,c=0,z=1,gd=0;
	string s;
	
	scanf("%lld%lld",&d,&m);
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&k);
		spc[k]=1;
	}
	for(i=1;i<=d;i++)
	{
		c--;
		if(spc[i])
		{
			c=n;
			if(i-l<n)
			{
				gd=__gcd(gd,i-l);
			}
			l=i;
		}
		if(c<=0)
		{
			z=z*26%dv;
		}
	}
	for(i=gd+1;i<=n;i++)
	{
		if(a[i]!=a[i-gd])
		{
			z*=0;
		}
	}
	printf("%lld\n",z);
}