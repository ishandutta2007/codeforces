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
#define N 300010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll n,a[N],b[N],sum1[N],sum2[N],nxt1[N],nxt2[N],nxt[N];
map<ll,ll> mp;
map<pair<ll,ll>,ll> dp;
int main(){
	ll i,j;
	n=rint();
	for(i=1;i<=n;++i)
	{
		a[i]=rint();
		sum1[i]=sum1[i-1]+a[i];
	}
	for(i=1;i<=n;++i)
	{
		b[i]=rint();
		sum2[i]=sum2[i-1]+b[i];
	}
	nxt1[n+1]=nxt2[n+1]=nxt[n+1]=n+1;
	mp.clear();
	for(i=n;i>=1;--i)
	{
		mp[sum1[i]]=i;
		nxt1[i]=nxt1[i+1];
		if(mp.count(sum1[i-1]))
		{
			nxt1[i]=min(nxt1[i],mp[sum1[i-1]]);
		}
	}
	mp.clear();
	for(i=n;i>=1;--i)
	{
		mp[sum2[i]]=i;
		nxt2[i]=nxt2[i+1];
		if(mp.count(sum2[i-1]))
		{
			nxt2[i]=min(nxt2[i],mp[sum2[i-1]]);
		}
	}
	mp.clear();
	for(i=n;i>=1;--i)
	{
		mp[sum1[i]+sum2[i]]=i;
		nxt[i]=nxt[i+1];
		if(mp.count(sum1[i-1]+sum2[i-1]))
		{
			nxt[i]=min(nxt[i],mp[sum1[i-1]+sum2[i-1]]);
		}
	}
	ll ans=0;
	priority_queue<pair<pair<ll,ll>,ll> > pq;
	pq.push(make_pair(make_pair(0,0),0));
	dp.clear();
	dp[make_pair(0,0)]=0;
	while(!pq.empty())
	{
		i=-pq.top().F.F;
		j=-pq.top().F.S;
		ll v=dp[make_pair(i,j)];
		ans=max(ans,v);
		if(pq.top().S!=v)
		{
			pq.pop();
			continue;
		}
		pq.pop();
		if(nxt1[i+1]<nxt2[j+1])
		{
			if(nxt1[i+1]<=n&&((!dp.count(make_pair(nxt1[i+1],j)))||dp[make_pair(nxt1[i+1],j)]<v+1))
			{
				dp[make_pair(nxt1[i+1],j)]=v+1;
				pq.push(make_pair(make_pair(-nxt1[i+1],-j),v+1));
			}
		}
		else
		{
			if(nxt2[j+1]<=n&&((!dp.count(make_pair(i,nxt2[j+1])))||dp[make_pair(i,nxt2[j+1])]<v+1))
			{
				dp[make_pair(i,nxt2[j+1])]=v+1;
				pq.push(make_pair(make_pair(-i,-nxt2[j+1]),v+1));
			}
		}
		ll x=nxt[max(i,j)+1];
		if(x<=n&&((!dp.count(make_pair(x,x)))||dp[make_pair(x,x)]<v+1))
		{
			dp[make_pair(x,x)]=v+1;
			pq.push(make_pair(make_pair(-x,-x),v+1));
		}
	}
	rout(ans),putchar('\n');
	return 0;
}