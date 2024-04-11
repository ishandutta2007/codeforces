#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n;
map<long long,long long> ls,ps;
map<long long,pair<long long,long long>> mne;
pair<pair<long long,long long>,pair<long long,long long>> z;

inline void ad(long long x,long long y,long long w)
{
	ls[x]=y;
	ps[x]=w;
	mne[x]=min(mne[x],{w,y});
	z=max(z,{{w-mne[x].fr,x},{mne[x].sc+1,y}});
}

int main()
{
	long long t,rr,i,k,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ls.clear();
		ps.clear();
		mne.clear();
		z.fr.fr=-inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			w=ps[k]-(i-1-ls[k]);
			ad(k,i-1,w);
			ad(k,i,w+1);
		}
		printf("%lld %lld %lld\n",z.fr.sc,z.sc.fr,z.sc.sc);
	}
}