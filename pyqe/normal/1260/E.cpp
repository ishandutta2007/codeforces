#include <bits/stdc++.h>

using namespace std;

long long n,a[300069];
priority_queue<long long> pq;

int main()
{
	long long i,j,p,pst,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(a[i]==-1)
		{
			pst=i;
		}
	}
	for(p=n,i=1;p>pst;i++)
	{
		pq.push(-a[p]);
		p--;
		z+=-pq.top();
		pq.pop();
		for(j=1;j<n>>i;j++,p--)
		{
			pq.push(-a[p]);
		}
	}
	printf("%lld\n",z);
}