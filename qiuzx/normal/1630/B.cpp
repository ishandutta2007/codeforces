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
#define ll int
#define N 200010
using namespace std;
ll n,k,a[N],cnt[N];
void solve(ll l,ll r)
{
	ll cnt,i,j;
	for(i=0;i<n&&k>1;i++,k--)
	{
		cnt=0;
		for(j=i;j<n;j++)
		{
			if(l<=a[j]&&a[j]<=r)
			{
				cnt++;
			}
			else
			{
				cnt--;
			}
			if(cnt>0)
			{
				printf("%d %d\n",i+1,j+1);
				i=j;
				break;
			}
		}
	}
	printf("%d %d\n",i+1,n);
	return;
}
int main(){
	ll T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<=n+1;i++)
		{
			cnt[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		for(i=1;i<=n;i++)
		{
			cnt[i]+=cnt[i-1];
		}
		ll mx=(n+k+1)/2;
		pair<ll,ll> pr=make_pair(-INF,INF);
		for(i=0;i<=n;i++)
		{
			ll nxt=lower_bound(cnt,cnt+n+1,cnt[i]+mx)-cnt;
			if(nxt-i<pr.S-pr.F&&cnt[nxt]-cnt[i]>=mx)
			{
				pr=make_pair(i,nxt);
			}
		}
		pr.F++;
		printf("%d %d\n",pr.F,pr.S);
		solve(pr.F,pr.S);
	}
	return 0;
}