#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<100069> vtdh,vtdv;

int main()
{
	long long i,j,z=0,c=0;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(j=0;j<m;j++)
		{
			if(s[j]=='S')
			{
				vtdh[i]=1;
				vtdv[j]=1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(!vtdh[i])
		{
			c++;
			z+=m;
		}
	}
	for(i=0;i<m;i++)
	{
		if(!vtdv[i])
		{
			z+=n-c;
		}
	}
	printf("%lld\n",z);
}