#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069],dsu[20];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long t,rr,i,ii,k,l,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			for(i=1;i<=n;i++)
			{
				a[ii][i]=s[i-1]-'a';
			}
		}
		for(i=0;i<20;i++)
		{
			dsu[i]=i;
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			k=a[0][i];
			l=a[1][i];
			if(k>l)
			{
				z=-1;
				break;
			}
			else
			{
				z+=fd(k)!=fd(l);
				dsu[fd(k)]=fd(l);
			}
		}
		printf("%lld\n",z);
	}
}