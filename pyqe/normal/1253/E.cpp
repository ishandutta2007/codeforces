#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nr[200069];
pair<long long,long long> a[80];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,k,w,l,ww;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	for(i=1;i<=m+m;i++)
	{
		nr[i]=1e18;
	}
	pq.push({0,1});
	nr[1]=0;
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		w=-pq.top().fr;
		pq.pop();
		if(k>m)
		{
			break;
		}
		if(w>nr[k])
		{
			continue;
		}
		for(i=0;i<n;i++)
		{
			if(k>=a[i].fr-a[i].sc&&k<=a[i].fr+a[i].sc)
			{
				l=a[i].fr+a[i].sc+1;
				ww=w;
			}
			else if(k>a[i].fr)
			{
				l=k+1;
				ww=w+1;
			}
			else
			{
				l=a[i].fr*2-k+1;
				ww=w+a[i].fr-a[i].sc-k;
			}
			if(ww<nr[l])
			{
				pq.push({-ww,l});
				nr[l]=ww;
			}
		}
	}
	printf("%lld\n",w);
}