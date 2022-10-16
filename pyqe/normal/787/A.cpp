#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long a[2],d[2];

int main()
{
	long long ii,e;
	pair<long long,long long> mne;
	
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld%lld",d+ii,a+ii);
	}
	if(abs(a[0]-a[1])%__gcd(d[0],d[1])!=0)
	{
		printf("-1\n");
		return 0;
	}
	for(;a[0]!=a[1];)
	{
		mne=min(mp(a[0],0),{a[1],1});
		e=mne.sc;
		a[e]+=d[e];
	}
	printf("%lld\n",a[0]);
}