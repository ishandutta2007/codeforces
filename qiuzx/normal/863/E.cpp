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
#define N 400010
using namespace std;
ll n,lo[N],hi[N],dif[N],dif2[N],sum[N],sum2[N];
vector<ll> allv;
int main(){
	ll i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&lo[i],&hi[i]);
		allv.push_back(lo[i]);
		allv.push_back(hi[i]);
	}
	sort(allv.begin(),allv.end());
	allv.erase(unique(allv.begin(),allv.end()),allv.end());
	for(i=0;i<n;i++)
	{
		lo[i]=lower_bound(allv.begin(),allv.end(),lo[i])-allv.begin();
		hi[i]=lower_bound(allv.begin(),allv.end(),hi[i])-allv.begin();
		dif[lo[i]]++;
		dif2[lo[i]]++;
		dif[hi[i]+1]--;
		dif2[hi[i]]--;
	}
	for(i=0;i<allv.size();i++)
	{
		sum[i+1]=(sum[i]+(dif[i]>=2));
		sum2[i+1]=(sum2[i]+(dif2[i]>=2||(i+1<allv.size()&&allv[i+1]==allv[i]+1)));
		dif[i+1]+=dif[i];
		dif2[i+1]+=dif2[i];
	}
	for(i=0;i<n;i++)
	{
		if(sum[hi[i]+1]-sum[lo[i]]==hi[i]-lo[i]+1&&sum2[hi[i]]-sum2[lo[i]]==hi[i]-lo[i])
		{
			printf("%d\n",i+1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}