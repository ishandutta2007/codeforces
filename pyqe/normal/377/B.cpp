#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,wg[100069],sq[100069];
pair<long long,long long> a[100069],as[100069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,j,r,k,l,w,pz,sm,lh,rh,md,zz=-1;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		a[i]={k,i};
	}
	sort(a+1,a+m+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		as[i]={k,i};
	}
	sort(as+1,as+n+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		scanf("%lld",wg+i);
	}
	for(lh=1,rh=m;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		for(j=1,i=1;i<=m;i+=md)
		{
			k=a[i].fr;
			for(;j<=n&&as[j].fr>=k;j++)
			{
				l=as[j].sc;
				pq.push({-wg[l],l});
			}
			if(pq.empty())
			{
				i=-1;
				break;
			}
			w=-pq.top().fr;
			pq.pop();
			sm+=w;
		}
		for(;!pq.empty();pq.pop());
		if(i!=-1&&sm<=d)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	if(zz==-1)
	{
		printf("NO\n");
	}
	else
	{
		for(j=1,i=1;i<=m;i+=zz)
		{
			k=a[i].fr;
			for(;j<=n&&as[j].fr>=k;j++)
			{
				l=as[j].sc;
				pq.push({-wg[l],l});
			}
			k=pq.top().sc;
			pq.pop();
			for(r=0;r<zz&&i+r<=m;r++)
			{
				pz=a[i+r].sc;
				sq[pz]=k;
			}
		}
		printf("YES\n");
		for(i=1;i<=m;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==m]);
		}
	}
}