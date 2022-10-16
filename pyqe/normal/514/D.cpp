#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn[5],fw[100069],fi,sq[5];
pair<long long,long long> sk[5][100069];

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

long long bl(long long x)
{
	long long i,p=0,sm=0;
	
	for(i=16;i+1;i--)
	{
		if(p+(1ll<<i)<=n&&sm+fw[p+(1ll<<i)]>x)
		{
			p+=1ll<<i;
			sm+=fw[p];
		}
	}
	return p+1;
}

int main()
{
	long long i,j,k,l,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%lld",&k);
			for(;nn[j]&&sk[j][nn[j]].sc<=k;nn[j]--)
			{
				l=sk[j][nn[j]].sc;
				ud(sk[j][nn[j]-1].fr+1,k-l);
				ud(sk[j][nn[j]].fr+1,l-k);
			}
			nn[j]++;
			sk[j][nn[j]]={i,k};
			ud(i,k);
			ud(i+1,-k);
		}
		k=bl(d);
		if(i+1-k>z)
		{
			z=i+1-k;
			for(j=0;j<m;j++)
			{
				sq[j]=lower_bound(sk[j]+1,sk[j]+nn[j]+1,mp(k,0ll))->sc;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==m-1]);
	}
}