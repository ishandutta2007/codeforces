#include <bits/stdc++.h>

using namespace std;

long long n,m,d,nn[2],a[2][1069];

int main()
{
	long long k,e,p;
	
	scanf("%lld%lld%lld",&n,&d,&m);
	for(;1;)
	{
		scanf("%lld",&k);
		e=k*2>m;
		if(e)
		{
			k*=-1;
		}
		p=upper_bound(a[e]+1,a[e]+nn[e]+1,k)-a[e];
		nn[e]+=p>nn[e];
		a[e][p]=k;
		if(e)
		{
			p=n+1-p;
		}
		printf("%lld\n",p);
		fflush(stdout);
		if(nn[0]+nn[1]==n)
		{
			break;
		}
	}
}