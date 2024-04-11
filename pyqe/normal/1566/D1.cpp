#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,pst[100069];
pair<long long,long long> a[100069];
bitset<369> vtd[369];

int main()
{
	long long t,rr,i,j,k,y,x,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n*m;i++)
		{
			scanf("%lld",&k);
			a[i]={k,-i};
		}
		sort(a+1,a+n*m+1);
		for(i=1;i<=n*m;i++)
		{
			k=-a[i].sc;
			pst[k]=i;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				vtd[i][j]=0;
			}
		}
		z=0;
		for(i=1;i<=n*m;i++)
		{
			y=(pst[i]-1)/m+1;
			x=(pst[i]-1)%m+1;
			for(j=1;j<x;j++)
			{
				z+=vtd[y][j];
			}
			vtd[y][x]=1;
		}
		printf("%lld\n",z);
	}
}