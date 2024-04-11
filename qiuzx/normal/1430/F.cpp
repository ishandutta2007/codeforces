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
#define N 2010
using namespace std;
ll n,k,lo[N],hi[N],a[N],f[N];
int main(){
	ll i;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&lo[i],&hi[i],&a[i]);
	}
	lo[n]=LINF;
	for(i=n-1;i>=0;i--)
	{
		f[i]=max((ll)0,a[i]+((hi[i]==lo[i+1])?f[i+1]:0)-(hi[i]-lo[i])*k);
	}
	ll ans=0,cur=0;
	for(i=0;i<n;i++)
	{
		if(cur<f[i])
		{
			ans+=cur;
			cur=k;
			if(k<f[i])
			{
				puts("-1");
				return 0;
			}
		}
		ans+=a[i];
		cur=(cur+k-(a[i]%k))%k;
	}
	printf("%lld\n",ans);
	return 0;
}