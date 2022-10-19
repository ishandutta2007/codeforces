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
ll n,a[N];
priority_queue<ll> pq;
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ll s=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			s+=a[i];
		}
		sort(a,a+n);
		ll cur=n-1;
		bool ans=true;
		while(!pq.empty())
		{
			pq.pop();
		}
		pq.push(s);
		while((!pq.empty())&&cur>=0)
		{
			ll x=pq.top();
			pq.pop();
			if(x<a[cur])
			{
				ans=false;
				break;
			}
			if(x==a[cur])
			{
				cur--;
				continue;
			}
			if(x==1)
			{
				ans=false;
				break;
			}
			pq.push(x/2);
			pq.push((x+1)/2);
		}
		if(cur>=0)
		{
			ans=false;
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}