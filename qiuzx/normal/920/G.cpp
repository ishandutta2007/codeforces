//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
vector<ll> fac;
ll pro[N],lg[N];
ll calc(ll x)
{
	ll i,ret=0;
	for(i=0;i<(1<<fac.size());++i)
	{
		if(__builtin_popcount(i)&1)
		{
			ret-=x/pro[i];
		}
		else
		{
			ret+=x/pro[i];
		}
	}
	return ret;
}
int main(){
	ll T,i,st,p,k,l,r,mid;
	lg[0]=lg[1]=0;
	for(i=2;i<N;++i)
	{
		lg[i]=lg[i/2]+1;
	}
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&st,&p,&k);
		fac.clear();
		for(i=2;i*i<=p;++i)
		{
			while(p%i==0)
			{
				fac.push_back(i);
				p/=i;
			}
		}
		if(p>1)
		{
			fac.push_back(p);
		}
		sort(fac.begin(),fac.end());
		fac.erase(unique(fac.begin(),fac.end()),fac.end());
		pro[0]=1;
		for(i=1;i<(1<<fac.size());++i)
		{
			pro[i]=pro[i^(i&(-i))]*fac[lg[i&(-i)]];
		}
		k+=calc(st);
		l=0;
		r=INF;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(calc(mid)>=k)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		printf("%lld\n",l);
	}
	return 0;
}