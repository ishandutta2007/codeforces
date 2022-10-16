#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dv=1e9+7;
pair<long long,long long> a[200069];
priority_queue<pair<long long,pair<long long,long long>>> pq;

int main()
{
	long long i,b=1e18,fq=1,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	sort(a,a+n,greater<pair<long long,long long>>());
	a[n]=mp(0,0);
	for(i=0;i<=n;i++)
	{
		for(;!pq.empty()&&pq.top().fr>=a[i].fr;pq.pop())
		{
			if(pq.top().sc.fr<b)
			{
				b=pq.top().sc.fr;
				fq=pq.top().sc.sc;
			}
			else if(pq.top().sc.fr==b)
			{
				fq=(fq+pq.top().sc.sc)%dv;
			}
		}
		if(b==1e18)
		{
			k=a[i].sc;
		}
		else
		{
			k=b-a[i].fr+a[i].sc;
		}
		pq.push(mp(a[i].sc,mp(k,fq)));
	}
	printf("%lld\n",fq);
}