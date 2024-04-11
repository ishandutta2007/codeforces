#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,nn=0,nm=0,a[300069],wg[300069],sk[300069],sq[300069];
pair<pair<long long,long long>,long long> rg[600069],qq[300069];
multiset<pair<long long,long long>> ms;

inline void ad(long long x,long long y)
{
	nm++;
	rg[nm]={{y,x},(a[y]-a[x])*(wg[x]+wg[y])};
}

int main()
{
	long long t,rr,i,k,l,w,k2,pz;
	multiset<pair<long long,long long>>::iterator it;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",a+i,wg+i);
		for(;nn&&wg[sk[nn]]>=wg[i];nn--)
		{
			ad(sk[nn],i);
		}
		if(nn)
		{
			ad(sk[nn],i);
		}
		nn++;
		sk[nn]=i;
	}
	sort(rg+1,rg+nm+1);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		qq[rr]={{l,k},rr};
	}
	sort(qq+1,qq+t+1);
	for(i=1,rr=1;rr<=t;rr++)
	{
		l=qq[rr].fr.fr;
		k=qq[rr].fr.sc;
		pz=qq[rr].sc;
		for(;i<=nm&&rg[i].fr.fr<=l;i++)
		{
			k2=rg[i].fr.sc;
			w=rg[i].sc;
			it=ms.lower_bound({k2,-inf});
			if(it==ms.end()||it->sc>w)
			{
				it=ms.upper_bound({k2,inf});
				if(it!=ms.begin())
				{
					for(it--;it->sc>=w;)
					{
						if(it!=ms.begin())
						{
							it--;
							ms.erase(next(it));
						}
						else
						{
							ms.erase(it);
							break;
						}
					}
				}
				ms.insert({k2,w});
			}
		}
		it=ms.lower_bound({k,-inf});
		sq[pz]=it->sc;
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}