#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
	#define sz 8333
	#define mod 998244353ll
	typedef long long ll;
	typedef double db;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
	templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
	templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
	templ inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
	char __sr[1<<21],__z[20];int __C=-1,__zz=0;
	inline void Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
	inline void print(int x)
	{
		if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
		while(__z[++__zz]=x%10+48,x/=10);
		while(__sr[++__C]=__z[__zz],--__zz);__sr[++__C]='\n';
	}
	void file()
	{
		#ifdef NTFOrz
		freopen("a.in","r",stdin);
		#endif
	}
	inline void chktime()
	{
		#ifdef NTFOrz
		cerr<<clock()/1000.0<<'\n';
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

ll fac[sz],_fac[sz];
void init(){_fac[0]=fac[0]=1;rep(i,1,sz-1) _fac[i]=inv(fac[i]=fac[i-1]*i%mod);}

int r[sz],limit;
void NTT_init(int n)
{
	int l=-1;
	for (limit=1;limit<=n;limit<<=1) ++l;
	rep(i,0,limit-1) r[i]=(r[i>>1]>>1)|((i&1)<<l);
}
void NTT(ll *a,int type)
{
	rep(i,0,limit-1) if (i<r[i]) swap(a[i],a[r[i]]);
	for (int mid=1;mid<limit;mid<<=1)
	{
		ll Wn=ksm(3,mod/mid>>1); if (type==-1) Wn=inv(Wn);
		for (int j=0;j<limit;j+=mid<<1)
		{
			ll w=1;
			rep(k,0,mid-1)
			{
				ll x=a[j+k],y=a[j+k+mid]*w%mod;
				a[j+k]=(x+y)%mod,a[j+k+mid]=(x-y+mod)%mod;
				w=w*Wn%mod;
			}
		}
	}
	if (type==1) return;
	ll I=inv(limit);
	rep(i,0,limit-1) a[i]=a[i]*I%mod;
}

int n,T;
int l[sz],L;

ll dp[55][55][sz],tmp1[sz],tmp2[sz],tmp3[sz];

int main()
{
	file();
	init();
	read(n,T); rep(i,1,n) read(l[i]),L+=l[i]; sort(l+1,l+n+1),reverse(l+1,l+n+1);
	dp[0][0][0]=1; NTT_init(L*2+5);
	rep(i,1,n) rep(t,0,i)
	{
		rep(k,0,L) tmp1[k]=dp[i-1][t][k]; NTT(tmp1,1);
		rep(k,0,(l[i]-1)/T)
		{
			ll p=(l[i]-k*T)*inv(L)%mod;
			tmp2[k]=((k&1)?mod-1:1)*_fac[k]%mod*ksm(p,k)%mod;
			if (k) tmp3[k]=((k&1)?mod-1:1)*_fac[k-1]%mod*ksm(p,k-1)%mod;
		}
		NTT(tmp2,1),NTT(tmp3,1);
		rep(i,0,limit-1) tmp2[i]=tmp2[i]*tmp1[i]%mod,tmp3[i]=tmp3[i]*tmp1[i]%mod;
		NTT(tmp2,-1),NTT(tmp3,-1);
		rep(k,0,L) (dp[i][t][k]+=tmp2[k])%=mod,(dp[i][t+1][k]+=tmp3[k])%=mod;
		rep(k,0,limit-1) tmp1[k]=tmp2[k]=tmp3[k]=0;
	}
//	rep(j,0,L/T) rep(k,0,(l[i]-1)/T) 
//	{
//		ll p=(l[i]-k*T)*inv(L)%mod;
//		(dp[i][j+k][t]+=((k&1)?mod-1:1)*_fac[k]%mod*ksm(p,k)%mod*dp[i-1][j][t]%mod)%=mod;
//		if (k) (dp[i][j+k][t+1]+=((k&1)?mod-1:1)*_fac[k-1]%mod*ksm(p,k-1)%mod*dp[i-1][j][t]%mod)%=mod;
//	}
	ll ans=0;
	rep(j,1,L/T) rep(t,0,min(j,n))
	{
		ll p=1-j*T%mod*inv(L)%mod;
		(ans+=dp[n][t][j]*ksm(1-p,mod-1-(j-t+1))%mod*fac[j-t]%mod+mod)%=mod;
	}
	chktime();
	ans=(mod-ans)%mod;
	cout<<ans;
	return 0;
}