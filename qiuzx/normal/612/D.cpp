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
#define N 2000010
using namespace std;
ll n,k,lo[N],hi[N],res[N],res2[N];
vector<ll> allv;
vector<pair<ll,ll> > ans,pnt;
int main(){
	ll i,j;
	scanf("%d%d",&n,&k);
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
		res[lo[i]]++;
		res2[lo[i]]++;
		res[hi[i]]--;
		res2[hi[i]+1]--;
	}
	for(i=0;i<allv.size();i++)
	{
		if(res2[i]>=k)
		{
			if(res[i]>=k)
			{
				pnt.push_back(make_pair(i,0));
			}
			else
			{
				pnt.push_back(make_pair(i,1));
			}
		}
		res2[i+1]+=res2[i];
		res[i+1]+=res[i];
	}
	for(i=0;i<pnt.size();i=j+1)
	{
		for(j=i;j<pnt.size();j++)
		{
			if(pnt[j].S)
			{
				break;
			}
		}
		ans.push_back(make_pair(allv[pnt[i].F],allv[pnt[j].F]));
	}
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%d %d\n",ans[i].F,ans[i].S);
	}
	return 0;
}