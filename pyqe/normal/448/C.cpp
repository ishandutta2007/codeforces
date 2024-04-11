#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[5069],inf=1e18;

long long bf(long long lh,long long rh,long long w)
{
	long long i,mn,e;
	pair<long long,long long> mne={inf,-1};
	
	if(lh>rh)
	{
		return 0;
	}
	for(i=lh;i<=rh;i++)
	{
		mne=min(mne,{a[i],i});
	}
	mn=mne.fr;
	e=mne.sc;
	return min(rh-lh+1,bf(lh,e-1,mn)+bf(e+1,rh,mn)+mn-w);
}

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	printf("%lld\n",bf(1,n,0));
}