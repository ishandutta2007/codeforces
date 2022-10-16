#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[169][169],fq[169];
pair<long long,long long> as[10069];

int main()
{
	long long t,rr,i,j,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&a[i][j]);
				as[(i-1)*m+j]={a[i][j],i};
			}
			sort(a[i]+1,a[i]+m+1);
			fq[i]=0;
		}
		sort(as+1,as+n*m+1);
		for(i=1;i<=m;i++)
		{
			fq[as[i].sc]++;
		}
		sm=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%lld%c",a[i][(j+m-sm-1)%m+1]," \n"[j==m]);
			}
			sm+=fq[i];
		}
	}
}