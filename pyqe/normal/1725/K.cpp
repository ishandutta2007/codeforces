#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,pst[400069],a[800069],dsu[800069];
multiset<pair<long long,long long>> ms;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

inline void ad(long long x,long long w)
{
	multiset<pair<long long,long long>>::iterator it;
	
	nn++;
	pst[x]=nn;
	dsu[nn]=nn;
	it=ms.lower_bound({w,0});
	if(it==ms.end()||it->fr!=w)
	{
		a[nn]=w;
		ms.insert({w,nn});
	}
	else
	{
		dsu[fd(nn)]=fd(it->sc);
	}
}

inline void mrg(long long lb,long long rb,long long w)
{
	long long k,l=0;
	multiset<pair<long long,long long>>::iterator it;
	
	for(it=ms.lower_bound({lb,0});it!=ms.end()&&it->fr<=rb;)
	{
		k=it->sc;
		if(l)
		{
			dsu[fd(l)]=fd(k);
		}
		l=k;
		it++;
		ms.erase(prev(it));
	}
	if(l)
	{
		a[fd(l)]=w;
		ms.insert({w,l});
	}
}

int main()
{
	long long t,rr,i,ky,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ad(i,k);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			scanf("%lld",&l);
			ad(k,l);
		}
		else if(ky==2)
		{
			printf("%lld\n",a[fd(pst[k])]);
		}
		else
		{
			scanf("%lld",&l);
			mrg(k-1,(k+l)/2,k-1);
			mrg((k+l)/2+1,l+1,l+1);
		}
	}
}