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
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll val[N],sum[N],pd[N],pds[N],rd[N],ch[N][2],sz[N],id[N],tot,rt,ans[N];
void init()
{
	tot=0,rt=0;
	memset(ch,0,sizeof(ch));
	memset(sz,0,sizeof(sz));
	memset(pd,0,sizeof(pd));
	memset(pds,0,sizeof(pds));
	memset(sum,0,sizeof(sum));
	return;
}
void pushup(ll x)
{
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
	return;
}
void pushdown(ll x)
{
	if(ch[x][0])
	{
		val[ch[x][0]]+=pd[x],pd[ch[x][0]]+=pd[x];
		sum[ch[x][0]]+=pds[x],pds[ch[x][0]]+=pds[x];
	}
	if(ch[x][1])
	{
		val[ch[x][1]]+=pd[x],pd[ch[x][1]]+=pd[x];
		sum[ch[x][1]]+=pds[x],pds[ch[x][1]]+=pds[x];
	}
	pd[x]=pds[x]=0;
	return;
}
void Split(ll cur,ll v,ll &x,ll &y)
{
	if(!cur)
	{
		x=y=0;
		return;
	}
	pushdown(cur);
	if(val[cur]<=v)
	{
		x=cur;
		Split(ch[cur][1],v,ch[cur][1],y);
	}
	else
	{
		y=cur;
		Split(ch[cur][0],v,x,ch[cur][0]);
	}
	pushup(cur);
	return;
}
void Splitone(ll cur,ll req,ll &x,ll &y)
{
	if(!cur)
	{
		x=y=0;
		return;
	}
	pushdown(cur);
	if(sz[ch[cur][0]]<req)
	{
		x=cur;
		Splitone(ch[cur][1],req-sz[ch[cur][0]]-1,ch[cur][1],y);
	}
	else
	{
		y=cur;
		Splitone(ch[cur][0],req,x,ch[cur][0]);
	}
	pushup(cur);
	return;
}
ll Merge(ll x,ll y)
{
	if((!x)||(!y))
	{
		return x|y;
	}
	if(rd[x]<=rd[y])
	{
		pushdown(x);
		ch[x][1]=Merge(ch[x][1],y);
		pushup(x);
		return x;
	}
	pushdown(y);
	ch[y][0]=Merge(x,ch[y][0]);
	pushup(y);
	return y;
}
void ins(ll x,ll bid)
{
	id[bid]=++tot;
	rd[tot]=rnd()%mod;
	sz[tot]=1;
	val[tot]=x;
	ll rt1,rt2;
	Split(rt,x,rt1,rt2);
	rt=Merge(Merge(rt1,tot),rt2);
	return;
}
void solve(ll x)
{
	pushdown(x);
	ans[id[x]]=sum[x];
	if(ch[x][0])
	{
		solve(ch[x][0]);
	}
	if(ch[x][1])
	{
		solve(ch[x][1]);
	}
	return;
}
ll n,q,v[N];
pair<ll,ll> ts[N];
bool cmp(pair<ll,ll> x,pair<ll,ll> y)
{
	return (x.S==y.S)?(x.F<y.F):(x.S>y.S);
}
int main(){
	ll i;
	init();
	n=rint();
	for(i=0;i<n;i++)
	{
		ts[i].F=rint(),ts[i].S=rint();
	}
	sort(ts,ts+n,cmp);
	q=rint();
	for(i=0;i<q;i++)
	{
		v[i]=rint();
		ins(v[i],i+1);
	}
	for(i=0;i<n;i++)
	{
		ll rt1,rt2;
		Split(rt,ts[i].F-1,rt1,rt2);
		while(rt2)
		{
			ll currt;
			Splitone(rt2,1,currt,rt2);
			if(val[currt]>=2*ts[i].F)
			{
				rt2=Merge(currt,rt2);
				val[rt2]-=ts[i].F;
				pd[rt2]-=ts[i].F;
				sum[rt2]++;
				pds[rt2]++;
				rt=Merge(rt1,rt2);
				break;
			}
			val[currt]-=ts[i].F;
			pd[currt]-=ts[i].F;
			sum[currt]++;
			pds[currt]++;
			ll rt3;
			Split(rt1,val[currt],rt1,rt3);
			rt1=Merge(Merge(rt1,currt),rt3);
		}
		if(!rt2)
		{
			rt=Merge(rt1,rt2);
		}
	}
	solve(rt);
	for(i=1;i<=q;i++)
	{
		rout(ans[i]),putchar(' ');
	}
	return 0;
}