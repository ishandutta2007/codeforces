#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,cr,ttl[2],a[2][2][200069],fq[2],z=0;
bitset<200069> vtd[2];

inline void ad(long long xx,long long x,bool kd)
{
	long long e=a[0][xx][x];
	
	if(a[0][xx][x]==a[1][xx][x]||vtd[xx][x])
	{
		return;
	}
	vtd[xx][x]=1;
	if(!fq[0]&&!fq[1])
	{
		cr=e;
	}
	if(e==cr)
	{
		fq[xx]++;
	}
	else if(fq[xx])
	{
		fq[xx]--;
	}
	else if(kd)
	{
		z++;
		fq[!xx]--;
	}
	else
	{
		vtd[xx][x]=0;
	}
}

int main()
{
	long long i,ii,jj;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(jj=0;jj<2;jj++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][jj][i]);
				ttl[ii]+=a[ii][jj][i];
			}
		}
	}
	if(ttl[0]!=ttl[1])
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			ad(ii,i,0);
		}
		for(ii=0;ii<2;ii++)
		{
			ad(ii,i,1);
		}
		z+=fq[0]+fq[1];
	}
	printf("%lld\n",z);
}