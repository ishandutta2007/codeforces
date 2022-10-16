#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,fq[100069],vi[100069];
vector<long long> fz[100069];

inline void ad(long long xx,long long x,long long w)
{
	if(vi[x]<xx)
	{
		fq[x]=0;
		vi[x]=xx;
	}
	fq[x]+=w;
}

int main()
{
	long long i,j,r,k,l,sz,sz2,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			fz[j].push_back(i);
		}
	}
	for(i=2;i<n;i++)
	{
		sz=fz[i].size();
		for(j=sz-1;j>=0;j--)
		{
			k=fz[i][j];
			ad(i,k,i/k-1);
			z=(z+k/__gcd(k,n-i)*(n-i)%dv*fq[k])%dv;
			sz2=fz[k].size();
			for(r=0;r<sz2-1;r++)
			{
				l=fz[k][r];
				ad(i,l,-fq[k]);
			}
		}
	}
	printf("%lld\n",z);
}