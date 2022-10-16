#include <bits/stdc++.h>

using namespace std;

const long long ma=2e6;
long long n,nn,ca[1000069],dsu[2000069],sq[2000069],zs=0;

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
	long long i,j,k,sz,p;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=ma+1;i++)
	{
		dsu[i]=i;
	}
	for(i=0;i<n;i++)
	{
		cin>>s;
		nn=s.length();
		for(j=1;j<=nn;j++)
		{
			ca[j]=s[j-1]-'a';
		}
		scanf("%lld",&sz);
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			for(;1;)
			{
				p=fd(k);
				if(p>k+nn-1)
				{
					break;
				}
				sq[p]=ca[p-k+1];
				zs=max(zs,p);
				dsu[p]=p+1;
			}
		}
	}
	for(i=1;i<=zs;i++)
	{
		printf("%c",(char)(sq[i]+'a'));
	}
	printf("\n");
}