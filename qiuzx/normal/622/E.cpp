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
#define N 500010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,ans=0,mxd=0,deps[N];
vector<ll> vt[N];
void dfs(ll x,ll lst,ll d)
{
	mxd=max(mxd,d);
	if(vt[x].size()==1)
	{
		++deps[d];
		return;
	}
	ll i;
	for(i=0;i<vt[x].size();++i)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x,d+1);
		}
	}
	return;
}
ll calc(ll x)
{
	ll i,lstt=0;
	for(i=0;i<=mxd;++i)
	{
		deps[i]=0;
	}
	mxd=0;
	dfs(x,0,0);
	for(i=0;i<=mxd;++i)
	{
		lstt=max(lstt,i)+deps[i];
	}
	return lstt;
}
int main(){
	ll i,x,y;
	n=rint();
	for(i=1;i<n;++i)
	{
		x=rint()-1,y=rint()-1;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	for(i=0;i<vt[0].size();++i)
	{
		ans=max(ans,calc(vt[0][i]));
	}
	printf("%d\n",ans);
	return 0;
}