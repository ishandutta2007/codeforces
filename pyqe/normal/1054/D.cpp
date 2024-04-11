#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,fu;
map<long long,long long> fq;

int main()
{
	long long i,k,xr=0,mn,e,z;
	pair<long long,long long> mne;
	
	fq[xr]++;
	scanf("%lld%lld",&n,&d);
	fu=(1<<d)-1;
	z=n*(n+1)/2;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		xr^=k;
		mne=min(mp(fq[xr],xr),{fq[fu^xr],fu^xr});
		mn=mne.fr;
		e=mne.sc;
		z-=mn;
		fq[e]++;
	}
	printf("%lld\n",z);
}