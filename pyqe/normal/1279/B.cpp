#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[100069];

int main()
{
	long long t,rr,i,sm,e;
	pair<long long,long long> mxe,ze;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		ze={0,0};
		sm=0;
		mxe={0,0};
		bad=0;
		e=0;
		for(i=0;i<=n;i++)
		{
			mxe=max(mxe,{a[i],i});
			if(!bad&&sm+a[i]>d)
			{
				sm-=mxe.fr;
				bad=1;
				e=mxe.sc;
			}
			if(bad&&sm+a[i]>d)
			{
				break;
			}
			sm+=a[i];
			ze=max(ze,{i-bad,e});
		}
		printf("%lld\n",ze.sc);
	}
}