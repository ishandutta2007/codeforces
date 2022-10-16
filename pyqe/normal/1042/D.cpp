#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,fw[200069],fi;
pair<long long,long long> as[200069],qq[200069];

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

int main()
{
	long long i,j,k,l,pz,sm=0,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		as[i]={sm,i};
		sm+=k;
		qq[i]={sm-d,i};
	}
	sort(as+1,as+n+1,greater<pair<long long,long long>>());
	sort(qq+1,qq+n+1,greater<pair<long long,long long>>());
	for(j=1,i=1;i<=n;i++)
	{
		k=qq[i].fr;
		pz=qq[i].sc;
		for(;j<=n&&as[j].fr>k;j++)
		{
			l=as[j].sc;
			ud(l,1);
		}
		z+=qr(pz);
	}
	printf("%lld\n",z);
}