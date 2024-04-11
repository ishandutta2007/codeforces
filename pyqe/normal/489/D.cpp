#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[3069];
vector<long long> al[3069];

int main()
{
	long long i,j,r,k,l,sz,szz,tg,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			fq[j]=0;
		}
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			szz=al[l].size();
			for(r=0;r<szz;r++)
			{
				tg=al[l][r];
				if(tg!=i)
				{
					z+=fq[tg];
					fq[tg]++;
				}
			}
		}
	}
	printf("%lld\n",z);
}