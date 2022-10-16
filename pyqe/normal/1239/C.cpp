#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[100069],z[100069],fw[100069],fwp;
priority_queue<pair<long long,long long>> pq;
priority_queue<long long> pq2;
queue<long long> q;

void ud(long long x,long long w)
{
	for(fwp=x;fwp<=100000;fwp+=fwp&-fwp)
	{
		fw[fwp]+=w;
	}
}

long long sm(long long x)
{
	long long zz=0;
	
	for(fwp=x;fwp>0;fwp-=fwp&-fwp)
	{
		zz+=fw[fwp];
	}
	return zz;
}

int main()
{
	long long i,k,p,cr=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		pq.push({-a[i],-i});
	}
	for(i=0;i<n;i++)
	{
		if(q.empty()&&pq2.empty())
		{
			cr=-pq.top().fr+d;
		}
		else
		{
			cr+=d;
		}
		for(;!pq.empty()&&-pq.top().fr<=cr;pq.pop())
		{
			p=-pq.top().sc;
			if(!sm(p))
			{
				q.push(p);
				ud(p,1);
			}
			else
			{
				pq2.push(-p);
			}
		}
		p=q.front();
		q.pop();
		z[p]=cr;
		ud(p,-1);
		for(;!pq2.empty()&&!sm(-pq2.top());pq2.pop())
		{
			p=-pq2.top();
			q.push(p);
			ud(p,1);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",z[i]," \n"[i==n]);
	}
}