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
ll n,a[N],mn[N],mx[N],dif[N],dp[N],ans=0;
bool brk[N];
vector<pair<ll,ll> > pre,vt;
set<pair<ll,ll> > st;
int main(){
	ll i,j;
	memset(mn,63,sizeof(mn));
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mn[a[i]]=min(mn[a[i]],i);
		mx[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(mn[i]>mx[i])
		{
			continue;
		}
		dif[mx[i]]--;
		dif[mn[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		dif[i]+=dif[i-1];
	}
	for(i=1;i<=n;i++)
	{
		if(mn[i]==mx[i])
		{
			ans+=(dif[mn[i]]==0);
		}
		else if(mn[i]<mx[i])
		{
			pre.push_back(make_pair(mn[i],mx[i]));
		}
	}
	sort(pre.begin(),pre.end());
	ll cmx=-INF;
	for(i=0;i<pre.size();i++)
	{
		if(pre[i].S<=cmx)
		{
			continue;
		}
		cmx=pre[i].S;
		vt.push_back(pre[i]);
	}
	brk[0]=true;
	for(i=1;i<vt.size();i++)
	{
		if(vt[i].F>vt[i-1].S)
		{
			brk[i]=true;
		}
	}
	dp[0]=2;
	st.insert(make_pair(2,0));
	for(i=1,j=0;i<vt.size();i++)
	{
		while(j<vt.size()&&vt[j].S<vt[i].F)
		{
			st.erase(make_pair(dp[j],j));
			j++;
		}
		if(st.empty())
		{
			dp[i]=dp[i-1]+2;
		}
		else
		{
			dp[i]=(*st.begin()).F+1;
		}
		st.insert(make_pair(dp[i],i));
	}
	printf("%lld\n",n-ans-dp[vt.size()-1]);
	return 0;
}