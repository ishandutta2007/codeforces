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
ll n,m,d,a[N],b[N];
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		scanf("%lld",&m);
		for(i=0;i<m;i++)
		{
			scanf("%lld",&b[i]);
		}
		vector<pair<ll,ll> > va,vb,tmp;
		for(i=0;i<n;i++)
		{
			ll num=1;
			while(a[i]%d==0)
			{
				num*=d;
				a[i]/=d;
			}
			tmp.push_back(make_pair(num,a[i]));
		}
		va.push_back(tmp[0]);
		for(i=1;i<n;i++)
		{
			if(tmp[i].S==tmp[i-1].S)
			{
				va[va.size()-1].F+=tmp[i].F;
			}
			else
			{
				va.push_back(tmp[i]);
			}
		}
		tmp.clear();
		for(i=0;i<m;i++)
		{
			ll num=1;
			while(b[i]%d==0)
			{
				num*=d;
				b[i]/=d;
			}
			tmp.push_back(make_pair(num,b[i]));
		}
		vb.push_back(tmp[0]);
		for(i=1;i<m;i++)
		{
			if(tmp[i].S==tmp[i-1].S)
			{
				vb[vb.size()-1].F+=tmp[i].F;
			}
			else
			{
				vb.push_back(tmp[i]);
			}
		}
		bool ok=true;
		if(va.size()!=vb.size())
		{
			puts("No");
			continue;
		}
		for(i=0;i<va.size();i++)
		{
			ok&=(va[i]==vb[i]);
		}
		puts(ok?"Yes":"No");
	}
	return 0;
}