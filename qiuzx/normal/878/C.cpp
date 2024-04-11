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
#define N 50010
using namespace std;
ll n,k;
struct Data{
	ll rg[2][10],sz;
	bool operator < (const Data &b) const{
		ll i;
		for(i=0;i<k;i++)
		{
			if(rg[1][i]>b.rg[0][i])
			{
				return false;
			}
		}
		return true;
	}
};
set<Data> st;
int main(){
	ll i;
	scanf("%lld%lld",&n,&k);
	while(n--)
	{
		Data cur;
		for(i=0;i<k;i++)
		{
			ll x;
			scanf("%lld",&x);
			cur.rg[0][i]=cur.rg[1][i]=x;
		}
		cur.sz=1;
		while(st.find(cur)!=st.end())
		{
			set<Data>::iterator it=st.find(cur);
			for(i=0;i<k;i++)
			{
				cur.rg[0][i]=min(cur.rg[0][i],(*it).rg[0][i]);
				cur.rg[1][i]=max(cur.rg[1][i],(*it).rg[1][i]);
			}
			cur.sz+=(*it).sz;
			st.erase(it);
		}
		st.insert(cur);
		printf("%lld\n",(*(--st.end())).sz);
	}
	return 0;
}