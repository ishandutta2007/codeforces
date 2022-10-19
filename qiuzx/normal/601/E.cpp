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
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 35010
#define P 10000019
using namespace std;
struct dp{
	ll dp[1010];
	vector<ll> p;
};
ll n,k,q,v[N],w[N],plc[N],pw[N];
bool vis[N];
vector<ll> ans;
struct SegmentTree{
	ll lo[N<<2],hi[N<<2];
	vector<ll> qry[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r;
		qry[x].clear();
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update(ll x,ll l,ll r,ll id)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			qry[x].push_back(id);
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,r,id);
		}
		if(mid<r)
		{
			update(a|1,l,r,id);
		}
		return;
	}
	void query(ll x,dp f)
	{
		ll tl=lo[x],tr=hi[x],i,j;
		if(tl>=ans.size())
		{
			return;
		}
		for(i=0;i<qry[x].size();i++)
		{
			f.p.push_back(qry[x][i]);
			for(j=k-w[qry[x][i]];j>=0;j--)
			{
				f.dp[j+w[qry[x][i]]]=max(f.dp[j+w[qry[x][i]]],f.dp[j]+v[qry[x][i]]);
			}
		}
		if(tl==tr)
		{
			ll cur=f.dp[0];
			for(i=1;i<=k;i++)
			{
				cur=max(cur,f.dp[i]);
				ans[tl]=(ans[tl]+cur*pw[i-1])%mod;
			}
			return;
		}
		ll a=x<<1;
		query(a,f);
		query(a|1,f);
		return;
	}
}segt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,x,tp,cnt;
	pw[0]=1;
	for(i=1;i<N;i++)
	{
		pw[i]=(pw[i-1]*P)%mod;
	}
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>v[i]>>w[i];
	}
	cin>>q;
	ans.push_back(0);
	segt.build(1,0,n+q);
	cnt=n;
	while(q--)
	{
		cin>>tp;
		if(tp==1)
		{
			cin>>v[cnt]>>w[cnt];
			plc[cnt++]=ans.size();
		}
		else if(tp==2)
		{
			cin>>x;
			x--;
			if(((x<n)?0:plc[x])<ans.size())
			{
				segt.update(1,(x<n)?0:plc[x],ans.size()-1,x);
			}
			vis[x]=true;
		}
		else
		{
			ans.push_back(0);
		}
	}
	for(i=0;i<cnt;i++)
	{
		if(!vis[i])
		{
			segt.update(1,plc[i],ans.size()-1,i);
		}
	}
	dp f;
	memset(f.dp,-63,sizeof(f.dp));
	f.dp[0]=0;
	f.p.clear();
	segt.query(1,f);
	for(i=1;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}