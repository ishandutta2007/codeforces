#include<bits/stdc++.h>
clock_t __t=clock();
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
	#define sz 101010
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
	inline void print(register int x)
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
		cout<<(clock()-__t)/1000.0<<'\n';
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

int n;
char s[sz];int a[sz];

namespace SA
{
	int sa[sz],tp[sz],cnt[sz],rnk[sz],_rnk[sz];
	int H[sz];
	int st[sz][21],lg2[sz];
	void Sort(int m)
	{
		rep(i,1,m) cnt[i]=0;
		rep(i,1,n) ++cnt[rnk[i]];
		rep(i,1,m) cnt[i]+=cnt[i-1];
		drep(i,n,1) sa[cnt[rnk[tp[i]]]--]=tp[i];
	}
	void init()
	{
		rep(i,1,n) rnk[i]=s[i],tp[i]=i;
		Sort(256);
		for (int w=1,p=0,m=256;p<n;m=p,w<<=1)
		{
			p=0;
			rep(i,1,w) tp[++p]=n-i+1;
			rep(i,1,n) if (sa[i]>w) tp[++p]=sa[i]-w;
			Sort(m);
			memcpy(_rnk,rnk,sizeof(rnk));
			rnk[sa[p=1]]=1;
			rep(i,2,n) rnk[sa[i]]=(_rnk[sa[i]]==_rnk[sa[i-1]]&&_rnk[sa[i]+w]==_rnk[sa[i-1]+w])?p:++p;
		}
		for (int i=1,j,k=0;i<=n;i++)
		{
			if (k) --k;
			j=sa[rnk[i]-1];
			while (s[i+k]==s[j+k]) ++k;
			H[rnk[i]]=k;
		}
		rep(i,1,n) st[i][0]=H[i];
		rep(j,1,20) rep(i,1,n-(1<<j)+1) st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		rep(i,2,n) lg2[i]=lg2[i>>1]+1;
	}
	int query(int l,int r){int len=lg2[r-l+1];return min(st[l][len],st[r-(1<<len)+1][len]);}
	int lcp(int x,int y){if (x>n||y>n) return 0;x=rnk[x],y=rnk[y];if (x>y) swap(x,y);return x==y?1e9:query(x+1,y);}
}
using SA::lcp;

int sum[sz][28];
int none(int l,int r,int c){return sum[r][c]-sum[l-1][c]<=0;}
pii qq(int l1,int r1,int l2,int r2)
{
	int len=lcp(l1,l2);
	if (len+1+lcp(l1+len+1,l2+len+1)<r1-l1+1) return MP(-1,-1);
	return MP(l2+len,a[l1+len]);
}

int g[sz][21],gg[sz][21];
ll ss[sz],tot;
ll cnt[sz][28];
ll w(ll d){return 1ll*((1<<(d+1))-1)*((1<<(d+1))-1);}

int main()
{
	file();
	cin>>(s+1); n=strlen(s+1);
	SA::init();
	rep(i,1,n) a[i]=s[i]-'a'+1;
	rep(i,1,n) rep(j,1,26) sum[i][j]=sum[i-1][j]+(a[i]==j);
	rep(i,1,n) g[i][0]=1;
	rep(j,1,20) rep(i,1<<j,n-(1<<j)+1) 
		gg[i][j]=(g[i-(1<<(j-1))][j-1]&&g[i+(1<<(j-1))][j-1]&&lcp(i-(1<<j)+1,i+1)>=(1<<j)-1),
		g[i][j]=(gg[i][j]&&none(i-(1<<j)+1,i-1,a[i]));
	rep(j,1,20) rep(i,1,n) if (g[i][j]) tot+=w(j),ss[i-(1<<j)+1]+=w(j),ss[i+(1<<j)]-=w(j);
	rep(j,1,20) rep(i,1,n) if (gg[i][j]) rep(k,1,26) if (none(i-(1<<j)+1,i,k)) cnt[i][k]+=w(j);
	rep(j,1,20) rep(i,1<<j,n-(1<<j)+1) if (!gg[i][j])
	{
		int x=g[i-(1<<(j-1))][j-1],y=g[i+(1<<(j-1))][j-1];
		if (!x&&!y) continue;
		int l1=i-(1<<j)+1,r1=i-1,l2=i+1,r2=i+(1<<j)-1;
		if (x&&none(i-(1<<j)+1,i-1,a[i]))
		{
			pii p=qq(l1,r1,l2,r2);
			if (p.fir!=-1) cnt[p.fir][p.sec]+=w(j);
		}
		if (y&&none(i+1,i+(1<<j)-1,a[i]))
		{
			pii p=qq(l2,r2,l1,r1);
			if (p.fir!=-1) cnt[p.fir][p.sec]+=w(j);
		}
	}
	ll ans=tot+n;
	rep(i,1,n) ss[i]+=ss[i-1];
	rep(i,1,n) rep(j,1,26) if (j!=a[i]) chkmax(ans,tot+n-ss[i]+cnt[i][j]);
	cout<<ans;
	return 0;
}