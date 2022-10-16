#include <bits/stdc++.h>

using namespace std;

long long n,z=0,ex=0,c[4];
priority_queue<long long> pq[4];

int main()
{
	long long i,j,ky,k,p;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==10)
		{
			ky=2;
		}
		else if(ky==11)
		{
			ky=3;
		}
		pq[ky].push(k);
		c[ky]++;
		if(ky==3)
		{
			z+=k;
		}
	}
	for(;!pq[1].empty()&&!pq[2].empty();)
	{
		z+=pq[1].top()+pq[2].top();
		pq[1].pop();
		pq[2].pop();
	}
	for(i=0;i<c[3];i++)
	{
		k=0;
		p=-1;
		for(j=0;j<3;j++)
		{
			if(!pq[j].empty()&&pq[j].top()>k)
			{
				k=pq[j].top();
				p=j;
			}
		}
		z+=k;
		if(p>=0)
		{
			pq[p].pop();
		}
	}
	printf("%lld\n",z);
}