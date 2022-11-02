#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define pll pair<ll,ll>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define sz 404040
	#define mod (ll(1e9+7))
	typedef long long ll;
	typedef double db;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	template<typename T>inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
	template<typename T>inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
	void file()
	{
		#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
		#endif
	}
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,Q;

int pri[66],cnt;
bool npri[333];
void init()
{
	int n=300;
	#define xx (i*pri[j])
	rep(i,2,n)
	{
		if (!npri[i]) pri[++cnt]=i;
		rep(j,1,cnt)
		{
			if (xx>n) break;
			npri[xx]=1;
			if (i%pri[j]==0) break;
		}
	}
	#undef xx
}

ll tr[sz<<2],tag[sz<<2];
ll S[sz<<2],tg[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void Mul(int k,int l,int r,ll mul){tag[k]=tag[k]*mul%mod;tr[k]=tr[k]*ksm(mul,r-l+1)%mod;}
void Or(int k,ll s){S[k]|=s;tg[k]|=s;}
void pushdown(int k,int l,int r)
{
	int mid=(l+r)>>1;
	if (tag[k]!=1) { Mul(lson,tag[k]); Mul(rson,tag[k]); }
	Or(ls,tg[k]);Or(rs,tg[k]);
	tag[k]=1;tg[k]=0;
} 
void pushup(int k){tr[k]=tr[ls]*tr[rs]%mod;S[k]=S[ls]|S[rs];}
void update(int k,int l,int r,int x,int y,ll mul,ll s)
{
	if (x<=l&&r<=y) return Mul(k,l,r,mul),Or(k,s);
	int mid=(l+r)>>1;
	pushdown(k,l,r);
	if (x<=mid) update(lson,x,y,mul,s);
	if (y>mid) update(rson,x,y,mul,s);
	pushup(k);
}
pll query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return MP(tr[k],S[k]);
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	pll ret(1,0),L,R;
	if (x<=mid) L=query(lson,x,y),ret.fir=ret.fir*L.fir%mod,ret.sec|=L.sec;
	if (y>mid) R=query(rson,x,y),ret.fir=ret.fir*R.fir%mod,ret.sec|=R.sec;
	return ret;
}
void build(int k,int l,int r)
{
	tag[k]=1;tg[k]=0;
	if (l==r) 
	{
		int x;read(x);
		tr[k]=x;
		rep(i,1,cnt)
			if (x%pri[i]==0)
				S[k]|=(1ll<<(i-1));
		return;
	}
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(k);
}
ll query(int l,int r)
{
	pll x=query(1,1,n,l,r);
	ll ret=x.fir;
	rep(i,1,cnt) 
		if (x.sec&(1ll<<(i-1)))
			ret=ret*(pri[i]-1)%mod*inv(pri[i])%mod;
	return ret;
}
void modify(int l,int r,int x)
{
	ll s=0;
	rep(i,1,cnt) 
		if (x%pri[i]==0)
			s|=(1ll<<(i-1));
	update(1,1,n,l,r,x,s);
}

int main()
{
	file();
	init();
	read(n,Q);
	build(1,1,n);
	char s[10];
	int x,y,z;
	while (Q--)
	{
		scanf("%s",s);read(x,y);
		if (s[0]=='T') printf("%I64d\n",query(x,y));
		else read(z),modify(x,y,z);
	}
	return 0;//
}