#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],d[100069];
priority_queue<long long> pq;

int main()
{
	long long i,z=0,k,l,sz=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",d+i);
	}
	for(i=0;i<n;i++)
	{
		pq.push(-a[i]-z);
		sz++;
		l=z;
		z+=d[i];
		k=0;
		for(;!pq.empty()&&-pq.top()<=z;pq.pop())
		{
			k+=-pq.top()-l;
			sz--;
		}
		k+=sz*d[i];
		printf("%lld%c",k," \n"[i==n-1]);
	}
}