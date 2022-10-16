#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i;
	
	scanf("%lld",&n);
	long long a[n],p[n];
	pair<long long,long long> b[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		b[i].first=a[i];
		b[i].second=i;
	}
	sort(b,b+n);
	for(i=0;i<n;i++)
	{
		p[b[i].second]=i;
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			printf("%lld %lld\n",b[p[i]+1].first-b[p[i]].first,b[n-1].first-b[p[i]].first);
		}
		else if(i==n-1)
		{
			printf("%lld %lld\n",b[p[i]].first-b[p[i]-1].first,b[p[i]].first-b[0].first);
		}
		else
		{
			printf("%lld %lld\n",min(b[p[i]+1].first-b[p[i]].first,b[p[i]].first-b[p[i]-1].first),max(b[n-1].first-b[p[i]].first,b[p[i]].first-b[0].first));
		}
	}
}