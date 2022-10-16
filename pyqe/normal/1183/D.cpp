#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> fq[500069];
priority_queue<long long> pq;

int main()
{
	long long t,rr,i,j,k,l=0,z,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			fq[i]={0,0};
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k].fr++;
			fq[k].sc+=l;
		}
		sort(fq+1,fq+n+1,greater<pair<long long,long long>>());
		z=0;
		zz=0;
		for(j=1,i=n;i>0;i--)
		{
			for(;j<=n&&fq[j].fr>=i;j++)
			{
				pq.push(fq[j].sc);
			}
			if(!pq.empty())
			{
				z+=i;
				zz+=min(i,pq.top());
				pq.pop();
			}
		}
		for(;!pq.empty();pq.pop());
		printf("%lld\n",z);
	}
}