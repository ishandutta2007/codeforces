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
struct SegmentTree{
	ll val[N<<2][10][10],clr[N<<2],lo[N<<2],hi[N<<2],ch[N<<2],pd[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l;
		hi[x]=r;
		clr[x]=-1;
		ch[x]=pd[x]=-1;
		memset(val[x],0,sizeof(val[x]));
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void pushdown(ll x)
	{
		ll a=x<<1,i,j;
		for(i=0;i<10;++i)
		{
			for(j=0;j<10;++j)
			{
				val[a][i][j]=val[a|1][i][j]=0;
			}
		}
		val[a][clr[x]][clr[x]]=hi[a]-lo[a]+1;
		val[a|1][clr[x]][clr[x]]=hi[a|1]-lo[a|1]+1;
		clr[a]=clr[a|1]=clr[x];
		clr[x]=-1;
		return;
	}
	void pushdown2(ll x)
	{
		ll a=x<<1;
		ch[a]=ch[a|1]=pd[x];
		pd[a]=pd[a|1]=pd[x];
		pd[x]=-1;
		return;
	}
	void modify(ll x,ll l,ll r,ll c)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			ch[x]=c;
			pd[x]=c;
			if(tl!=tr)
			{
				pushdown2(x);
			}
			return;
		}
		if(pd[x]!=-1)
		{
			pushdown2(x);
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			modify(a,l,r,c);
		}
		if(mid<r)
		{
			modify(a|1,l,r,c);
		}
		return;
	}
	ll query(ll x,ll l)
	{
		ll tl=lo[x],tr=hi[x];
		if(l==tl&&tr==l)
		{
			return ch[x];
		}
		if(pd[x]!=-1)
		{
			pushdown2(x);
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			return query(a,l);
		}
		return query(a|1,l);
	}
	void update1(ll x,ll l,ll c1,ll c2,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(l==tl&&tr==l)
		{
			val[x][c1][c2]+=v;
			return;
		}
		if(clr[x]>=0)
		{
			pushdown(x);
		}
		ll mid=(tl+tr)>>1,a=x<<1,i,j;
		if(mid>=l)
		{
			update1(a,l,c1,c2,v);
		}
		else
		{
			update1(a|1,l,c1,c2,v);
		}
		for(i=0;i<10;++i)
		{
			for(j=0;j<10;++j)
			{
				val[x][i][j]=val[a][i][j]+val[a|1][i][j];
			}
		}
		return;
	}
	void update2(ll x,ll l,ll r,ll c)
	{
		ll tl=lo[x],tr=hi[x],i,j;
		if(l<=tl&&tr<=r)
		{
			for(i=0;i<10;++i)
			{
				for(j=0;j<10;++j)
				{
					val[x][i][j]=0;
				}
			}
			val[x][c][c]=tr-tl+1;
			clr[x]=c;
			if(tl!=tr)
			{
				pushdown(x);
			}
			return;
		}
		if(clr[x]!=-1)
		{
			pushdown(x);
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update2(a,l,r,c);
		}
		if(mid<r)
		{
			update2(a|1,l,r,c);
		}
		for(i=0;i<10;++i)
		{
			for(j=0;j<10;++j)
			{
				val[x][i][j]=val[a][i][j]+val[a|1][i][j];
			}
		}
		return;
	}
}segt;
ll n,m,k;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,tp;
	cin>>n>>m>>k;
	segt.build(1,0,n-1);
	cin>>s;
	for(i=0;i<n;++i)
	{
		segt.modify(1,i,i,s[i]-'a');
		if(i+1<n)
		{
			segt.update1(1,i,s[i]-'a',s[i+1]-'a',1);
		}
	}
	while(m--)
	{
		cin>>tp;
		if(tp==1)
		{
			ll l,r;
			char c;
			cin>>l>>r>>c;
			--l,--r;
			if(l<r)
			{
				segt.update2(1,l,r-1,c-'a');
			}
			if(l>0)
			{
				ll x1=segt.query(1,l-1),x2=segt.query(1,l);
//				cout<<x1<<","<<x2<<endl;
				segt.update1(1,l-1,x1,x2,-1);
				segt.update1(1,l-1,x1,c-'a',1);
			}
			if(r+1<n)
			{
				ll x1=segt.query(1,r),x2=segt.query(1,r+1);
//				cout<<x1<<","<<x2<<endl;
				segt.update1(1,r,x1,x2,-1);
				segt.update1(1,r,c-'a',x2,1);
			}
			segt.modify(1,l,r,c-'a');
		}
		else
		{
			string c;
			cin>>c;
			ll ans=n;
			for(i=0;i<k;++i)
			{
				for(j=i+1;j<k;++j)
				{
					ans-=segt.val[1][c[i]-'a'][c[j]-'a'];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}