#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,inf=1e18,mn[2]={inf,inf},mx[2]={-inf,-inf};
pair<long long,long long> a[300069];

int main()
{
	long long i,ii,p[2],sm,z=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	for(i=1;i<=n;i++)
	{
		p[0]=a[i].fr;
		p[1]=a[i].sc;
		for(ii=0;ii<2;ii++)
		{
			mn[ii]=min(mn[ii],p[ii]);
			mx[ii]=max(mx[ii],p[ii]);
		}
	}
	for(i=1;i<=n;i++)
	{
		p[0]=a[i].fr;
		p[1]=a[i].sc;
		sm=0;
		for(ii=0;ii<2;ii++)
		{
			sm+=max(abs(p[ii]-mn[ii]),abs(p[ii]-mx[ii]))*2;
		}
		z=max(z,sm);
	}
	printf("%lld",z);
	for(i=4;i<=n;i++)
	{
		printf(" %lld",(mx[0]-mn[0]+mx[1]-mn[1])*2);
	}
	printf("\n");
}