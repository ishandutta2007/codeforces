#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[200069];
priority_queue<long long> pq;

int main()
{
	long long i,j,k,w,sm=0,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].sc);
	}
	sort(a+1,a+n+1);
	a[n+1]={1e18,0};
	for(i=1;i<=n+1;i++)
	{
		k=a[i].fr;
		w=a[i].sc;
		for(j=0;!pq.empty()&&j<k-a[i-1].fr;pq.pop(),j++)
		{
			sm-=pq.top();
			z+=sm;
		}
		pq.push(w);
		sm+=w;
	}
	printf("%lld\n",z);
}