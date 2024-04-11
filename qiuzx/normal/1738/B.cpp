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
ll n,k,a[N];
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=n-k+1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		if(k==1)
		{
			puts("Yes");
			continue;
		}
		ll lst=LINF;
		bool ok=true;
		for(i=n;i>n-k+1;i--)
		{
			ll cur=a[i]-a[i-1];
			if(lst<cur)
			{
				ok=false;
				break;
			}
			lst=cur;
		}
		if((!ok)||a[n-k+1]>(n-k+1)*lst)
		{
			puts("No");
		}
		else
		{
			puts("Yes");
		}
	}
	return 0;
}