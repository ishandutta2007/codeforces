#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n;

int main()
{
	long long t,rr,i,k,mn,e;
	pair<long long,long long> mne;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mne={inf,-1};
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			mne=min(mne,{k,i});
		}
		mn=mne.fr;
		e=mne.sc;
		printf("%lld\n",n-1);
		for(i=1;i<=n;i++)
		{
			if(i==e)
			{
				continue;
			}
			if(i%2==e%2)
			{
				printf("%lld %lld %lld %lld\n",e,i,mn,mn);
			}
			else
			{
				printf("%lld %lld %lld %lld\n",e,i,mn,mn+1);
			}
		}
	}
}