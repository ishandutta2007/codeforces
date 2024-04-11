#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,ma,m[2],nn[2];
pair<long long,long long> a[2][200069],sk[2][200069];

int main()
{
	long long i,j,ii,mn=5e18;
	
	scanf("%lld%lld%lld%lld%lld",&n,m,m+1,&d,&ma);
	sk[0][1]={0,-d};
	sk[1][1]={0,0};
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=m[ii];i++)
		{
			scanf("%lld",&a[ii][i].sc);
		}
		for(i=1;i<=m[ii];i++)
		{
			scanf("%lld",&a[ii][i].fr);
			if(!ii)
			{
				a[ii][i].sc*=-1;
			}
		}
		sort(a[ii]+1,a[ii]+m[ii]+1);
		nn[ii]=1;
		for(i=1;i<=m[ii];i++)
		{
			if(a[ii][i].sc>sk[ii][nn[ii]].sc)
			{
				nn[ii]++;
				sk[ii][nn[ii]]=a[ii][i];
			}
		}
	}
	for(j=nn[1],i=1;i<=nn[0]&&sk[0][i].fr<=ma;i++)
	{
		for(;sk[0][i].fr+sk[1][j].fr>ma;j--);
		mn=min(mn,max(n-sk[1][j].sc,0ll)*-sk[0][i].sc);
	}
	printf("%lld\n",mn);
}