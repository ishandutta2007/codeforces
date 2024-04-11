#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,inf=1e18;

int main()
{
	long long t,rr,i,k,l,st,e;
	pair<long long,long long> mne;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&k,&l);
		mne={inf,-1};
		for(i=1;i<=l-k;i++)
		{
			if((l-k)%i==0&&(l-k)/i<n)
			{
				st=max(l-i*(n-1),(k-1)%i+1);
				mne=min(mne,{st+i*(n-1),i});
			}
		}
		e=mne.sc;
		st=max(l-e*(n-1),(k-1)%e+1);
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",st+e*(i-1)," \n"[i==n]);
		}
	}
}