#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[100069],wg[100069];
priority_queue<pair<long long,long long>> pq;

long long sqr(long long x)
{
	return x*x;
}

long long val(long long x,long long y)
{
	return sqr(x/y+1)*(x%y)+sqr(x/y)*(y-x%y);
}

int main()
{
	long long i,k,w,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		z+=val(a[i],1);
		wg[i]=1;
		pq.push({val(a[i],1)-val(a[i],2),i});
	}
	for(i=0;i<d-n;i++)
	{
		w=pq.top().fr;
		k=pq.top().sc;
		pq.pop();
		z-=w;
		wg[k]++;
		pq.push({val(a[k],wg[k])-val(a[k],wg[k]+1),k});
	}
	printf("%lld\n",z);
}