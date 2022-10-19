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
#define N 1000010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
multiset<ll> idx[N];
ll n,q,a[N],par[N],app[N],nums[N],ans[N];
vector<ll> vt[N];
vector<pair<ll,pair<ll,ll> > > qry[N];
void update(ll x)
{
	idx[app[a[x]]].erase(a[x]);
	--nums[app[a[x]]];
	++app[a[x]];
	idx[app[a[x]]].insert(a[x]);
	return;
}
ll query(ll st,ll num)
{
	num+=nums[st-1];
	ll l=0,r=n+1,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(nums[mid]<num)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	++l;
	if(idx[l].size()<1)
	{
		return -1;
	}
	return *idx[l].begin();
}
void recall(ll x)
{
	idx[app[a[x]]].erase(a[x]);
	--app[a[x]];
	++nums[app[a[x]]];
	idx[app[a[x]]].insert(a[x]);
	return;
}
void dfs(ll x)
{
	update(x);
	ll i;
	for(i=0;i<qry[x].size();++i)
	{
		ans[qry[x][i].F]=query(qry[x][i].S.F,qry[x][i].S.S);
	}
	for(i=0;i<vt[x].size();++i)
	{
		dfs(vt[x][i]);
	}
	recall(x);
	return;
}
int main(){
	ll T,i;
	T=rint();
	while(T--)
	{
		n=rint(),q=rint();
		for(i=0;i<=n;++i)
		{
			idx[i].clear();
			nums[i]=n;
			app[i]=0;
		}
		for(i=0;i<n;++i)
		{
			idx[0].insert(i);
			vt[i].clear();
			qry[i].clear();
			a[i]=rint();
		}
		for(i=1;i<n;++i)
		{
			par[i]=rint()-1;
			vt[par[i]].push_back(i);
		}
		for(i=0;i<q;++i)
		{
			ll x=rint()-1,y=rint(),z=rint();
			qry[x].push_back(make_pair(i,make_pair(y,z)));
//			qry[rint()-1].push_back(make_pair(i,make_pair(rint(),rint())));
		}
		dfs(0);
		for(i=0;i<q;++i)
		{
			if(ans[i]==-1)
			{
				printf("-1 ");
			}
			else
			{
				rout(ans[i]),putchar(' ');
			}
		}
		puts("");
	}
	return 0;
}