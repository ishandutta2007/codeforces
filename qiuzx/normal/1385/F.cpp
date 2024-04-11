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
void rout(ll x){
	if(x<0) putchar('-'),rout(-x);
	else if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,k,deg[N],cnt[N];
vector<ll> vt[N];
set<pair<ll,ll> > st;
void solve()
{
	ll i,x,y,j;
	n=rint(),k=rint();
	for(i=0;i<n;++i)
	{
		deg[i]=cnt[i]=0;
		vt[i].clear();
	}
	for(i=1;i<n;++i)
	{
		x=rint()-1,y=rint()-1;
		deg[x]++;
		deg[y]++;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	if(k==1)
	{
		rout(n-1);
		putchar('\n');
		return;
	}
	st.clear();
	for(i=0;i<n;++i)
	{
		for(j=0;j<vt[i].size();++j)
		{
			if(deg[vt[i][j]]==1)
			{
				++cnt[i];
			}
		}
		if(cnt[i]>=k)
		{
			st.insert(make_pair(-cnt[i],i));
		}
	}
	ll ans=0;
	while(!st.empty())
	{
		x=(*st.begin()).S;
		st.erase(st.begin());
		ll cur=0;
		ans+=cnt[x]/k;
		deg[x]-=(cnt[x]/k)*k;
		cnt[x]%=k;
		if(deg[x]<=1)
		{
			for(i=0;i<vt[x].size();++i)
			{
				if(deg[vt[x][i]]>1)
				{
					if(cnt[vt[x][i]]>=k)
					{
						st.erase(st.lower_bound(make_pair(-cnt[vt[x][i]],vt[x][i])));
					}
					++cnt[vt[x][i]];
					if(cnt[vt[x][i]]>=k)
					{
						st.insert(make_pair(-cnt[vt[x][i]],vt[x][i]));
					}
				}
			}
		}
	}
	rout(ans);
	putchar('\n');
	return;
}
int main(){
	ll T=rint();
	while(T--)
	{
		solve();
	}
	return 0;
}