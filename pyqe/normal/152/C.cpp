#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,m,fq[169];
bitset<26> vtd[169];

int main()
{
	long long i,j,k,z=1;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&ch);
			k=ch-'A';
			fq[j]+=!vtd[j][k];
			vtd[j][k]=1;
		}
	}
	for(i=1;i<=m;i++)
	{
		z=z*fq[i]%dv;
	}
	printf("%lld\n",z);
}