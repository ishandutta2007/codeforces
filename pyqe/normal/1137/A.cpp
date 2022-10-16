#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,od[2][1069][1069],fq[2][1069];
pair<long long,long long> as[2][1069][1069];

int main()
{
	long long i,j,ii,k,l,mx,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			for(ii=0;ii<2;ii++)
			{
				as[ii][i][j]={k,j};
				swap(i,j);
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			sort(as[ii][i]+1,as[ii][i]+m+1);
			for(j=1;j<=m;j++)
			{
				k=as[ii][i][j].fr;
				l=as[ii][i][j].sc;
				if(k>as[ii][i][j-1].fr)
				{
					fq[ii][i]++;
				}
				od[ii][i][l]=fq[ii][i];
			}
		}
		swap(n,m);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			mx=-1e18;
			z=-1e18;
			for(ii=0;ii<2;ii++)
			{
				mx=max(mx,od[ii][i][j]);
				z=max(z,fq[ii][i]-od[ii][i][j]);
				swap(i,j);
			}
			printf("%lld%c",mx+z," \n"[j==m]);
		}
	}
}