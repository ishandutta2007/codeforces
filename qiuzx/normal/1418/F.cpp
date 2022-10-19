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
#define N 200010
using namespace std;
ll n,m,l,r,num[N];
vector<ll> fac[N];
set<ll> allf;
int main(){
	ll i,j;
	for(i=1;i<N;i++)
	{
		for(j=i;j<N;j+=i)
		{
			fac[j].push_back(i);
		}
	}
	cin>>n>>m>>l>>r;
	ll curl,curr;
	curl=curr=m;
	for(i=1;i<=n;i++)
	{
		ll nxtl=(l+i-1)/i,nxtr=min(m,r/i);
		if(nxtl>nxtr)
		{
			puts("-1");
			continue;
		}
		while(curl>=nxtl)
		{
			for(j=0;j<fac[curl].size();j++)
			{
				num[fac[curl][j]]++;
				if(num[fac[curl][j]]<=1)
				{
					allf.insert(fac[curl][j]);
				}
			}
			curl--;
		}
		while(curr>nxtr)
		{
			for(j=0;j<fac[curr].size();j++)
			{
				num[fac[curr][j]]--;
				if(num[fac[curr][j]]==0)
				{
					allf.erase(fac[curr][j]);
				}
			}
			curr--;
		}
		bool ok=false;
		for(j=0;j<fac[i].size();j++)
		{
			set<ll>::iterator it=allf.upper_bound(fac[i][j]);
			if(it==allf.end())
			{
				continue;
			}
			ll mny=*it;
			if(i/fac[i][j]*mny<=n)
			{
				printf("%lld %lld %lld %lld\n",i,(curr/mny)*mny,i/fac[i][j]*mny,(curr/mny)*fac[i][j]);
				ok=true;
				break;
			}
		}
		if(!ok)
		{
			puts("-1");
		}
	}
	return 0;
}