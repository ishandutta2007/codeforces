#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n;

int main()
{
	long long t,rr,i,k;
	pair<long long,long long> mne,mxe;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mne.fr=inf;
		mxe.fr=-inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			mne=min(mne,{k,i});
			mxe=max(mxe,{k,i});
		}
		printf("%lld %lld\n",mne.sc,mxe.sc);
	}
}