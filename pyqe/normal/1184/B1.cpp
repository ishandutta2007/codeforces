#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,sq[100069];
pair<long long,long long> qq[100069],a[100069];

int main()
{
	long long i,j,k,l,pz,sm=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&qq[i].fr);
		qq[i].sc=i;
	}
	sort(qq+1,qq+n+1);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={k,l};
	}
	sort(a+1,a+m+1);
	for(j=1,i=1;i<=n;i++)
	{
		k=qq[i].fr;
		pz=qq[i].sc;
		for(;j<=m&&a[j].fr<=k;j++)
		{
			sm+=a[j].sc;
		}
		sq[pz]=sm;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}