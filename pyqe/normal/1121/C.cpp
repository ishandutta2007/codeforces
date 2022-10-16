#include <bits/stdc++.h>

using namespace std;

long long n,d,aa[1069],a[1069],ti[1069],pg[1069];
priority_queue<long long> pq;

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<d;i++)
	{
		pq.push(0);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",aa+i);
		a[i]=-pq.top();
		pq.pop();
		pq.push(-aa[i]-a[i]);
		pg[i]=i*100/n+(i*100%n>=(n+1)/2);
	}
	for(i=1;i<=n;i++)
	{
		if(i<=n-d)
		{
			ti[i]=a[i+d];
		}
		else
		{
			ti[i]=-pq.top();
			pq.pop();
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(pg[j-1]&&pg[j-1]<=aa[i]&&pg[j-1]+a[i]>ti[j-1]&&pg[j-1]+a[i]<=ti[j])
			{
				z++;
				break;
			}
		}
	}
	printf("%lld\n",z);
}