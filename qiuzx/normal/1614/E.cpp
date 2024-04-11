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
struct SegT{
	ll lo[N*50],hi[N*50],val[N*50],ch[N*50][2],cnt;
	void init()
	{
		memset(lo,0,sizeof(lo));
		memset(hi,0,sizeof(hi));
		memset(val,0,sizeof(val));
		memset(ch,0,sizeof(ch));
		lo[1]=0;
		hi[1]=INF;
		cnt=1;
		return;
	}
	void update(ll x,ll p,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(tl==tr)
		{
			val[x]+=v;
			return;
		}
		ll mid=(tl+tr)>>1;
		if(mid>=p)
		{
			if(ch[x][0]==0)
			{
				ch[x][0]=++cnt;
				lo[ch[x][0]]=tl;
				hi[ch[x][0]]=mid;
			}
			update(ch[x][0],p,v);
		}
		else
		{
			if(ch[x][1]==0)
			{
				ch[x][1]=++cnt;
				lo[ch[x][1]]=mid+1;
				hi[ch[x][1]]=tr;
			}
			update(ch[x][1],p,v);
		}
		val[x]=val[ch[x][0]]+val[ch[x][1]];
		return;
	}
	ll query(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return val[x];
		}
		ll mid=(tl+tr)>>1,ret=0;
		if(mid>=l&&ch[x][0]!=0)
		{
			ret+=query(ch[x][0],l,r);
		}
		if(mid<r&&ch[x][1]!=0)
		{
			ret+=query(ch[x][1],l,r);
		}
		return ret;
	}
	ll fd1(ll x,ll tl,ll tr,ll p)
	{
		if(tl==tr)
		{
			return (tl+val[x]==p)?tl:-1;
		}
		ll mid=(tl+tr)>>1;
		if(mid+val[ch[x][0]]>=p)
		{
			return fd1(ch[x][0],tl,mid,p);
		}
		return fd1(ch[x][1],mid+1,tr,p-val[ch[x][0]]);
	}
	ll fd2(ll x,ll tl,ll tr,ll p)
	{
		if(tl==tr)
		{
			return (tl+val[x]==p)?tl:-1;
		}
		ll mid=(tl+tr)>>1;
		if(mid+val[ch[x][0]]>p)
		{
			return fd2(ch[x][0],tl,mid,p);
		}
		else if(mid+val[ch[x][0]]==p)
		{
			return max(fd2(ch[x][1],mid+1,tr,p-val[ch[x][0]]),mid);
		}
		return fd2(ch[x][1],mid+1,tr,p-val[ch[x][0]]);
	}
	void newday(ll t)
	{
		ll d1=fd1(1,0,INF,t),d2=fd2(1,0,INF,t),mn=query(1,0,0);
		if(mn>t)
		{
			update(1,0,-1);
			return;
		}
		update(1,0,1);
		if(d1>=0)
		{
			update(1,d1,-1);
			if(d2<INF)
			{
				update(1,d2+1,-1);
			}
		}
		return;
	}
}segt;
ll n,t,k;
int main(){
	ll i,x,lstans=0;
	segt.init();
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&t,&k);
		segt.newday(t);
		while(k--)
		{
			scanf("%d",&x);
			x=(x+lstans)%(INF+1);
			lstans=x+segt.query(1,0,x);
			printf("%d\n",lstans);
		}
	}
	return 0;
}