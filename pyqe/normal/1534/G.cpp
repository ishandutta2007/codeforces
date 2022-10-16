#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[800069];
priority_queue<long long> pq[2];

int main()
{
	long long i,ii,y,x,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&y,&x);
		y+=x;
		a[i]={y,x};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		y=a[i].fr;
		x=a[i].sc;
		if(i-1)
		{
			z+=max(pq[0].top()-x,0ll)+max(x-(-pq[1].top()+y),0ll);
		}
		if(i==1||x<=pq[0].top())
		{
			for(ii=0;ii<2;ii++)
			{
				pq[0].push(x);
			}
			pq[1].push(-(pq[0].top()-y));
			pq[0].pop();
		}
		else
		{
			for(ii=0;ii<2;ii++)
			{
				pq[1].push(-(x-y));
			}
			pq[0].push(-pq[1].top()+y);
			pq[1].pop();
		}
	}
	printf("%lld\n",z);
}