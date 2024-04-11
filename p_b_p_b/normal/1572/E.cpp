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
	#define sz 422
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

int n,K;
struct pt
{
	ll x,y;
	pt(ll X=0,ll Y=0){x=X,y=Y;}
	const pt operator + (const pt &a) const {return pt(x+a.x,y+a.y);}
	const pt operator - (const pt &a) const {return pt(x-a.x,y-a.y);}
}a[sz];
int nxt[sz],pre[sz];
ll Dot(pt a,pt b){return a.x*b.x+a.y*b.y;}
ll Cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
ll S(int i,int j,int k){return abs(Cross(a[i]-a[j],a[i]-a[k]));}

int dp[sz][sz]; pii pos[sz][sz];
int check(ll w)
{
	rep(i,0,n-1) rep(j,0,n-1) dp[i][j]=-1e7,pos[i][j]=MP(-1,-1);
	rep(len,2,n-1) rep(i,0,n-1)
	{
		int j=(i+len)%n;
		ll sum=0; for (int k=nxt[i];k!=j;k=nxt[k]) sum+=S(k,pre[k],j);
		if (sum<w) continue;
		dp[i][j]=1;
		for (int k=nxt[i];k!=j;k=nxt[k]) if (S(i,j,k)>=w&&chkmax(dp[i][j],1+dp[i][k]+dp[k][j])) pos[i][j]=MP(k,k);
		int l=i,r=j; ll cur=0;
		while (cur<w) r=pre[r],cur+=S(l,r,nxt[r]);
		chkmax(dp[i][j],dp[l][r]+1);
		while (l!=pre[j])
		{
			l=nxt[l]; if (pre[l]!=r) cur+=S(l,r,pre[l]); else r=l,cur=sum;
			while (r!=j&&cur-S(l,r,nxt[r])>=w) cur-=S(l,r,nxt[r]),r=nxt[r];
			if (chkmax(dp[i][j],1+dp[l][r])) pos[i][j]=MP(l,r);
		}
	}
	int mx=0;
	rep(l,0,n-1) rep(r,l+2,n-1) chkmax(mx,dp[l][r]+dp[r][l]-1);
	return mx;
}

int main()
{
	file();
	read(n,K);
	rep(i,0,n-1) read(a[i].x,a[i].y),pre[i]=(i-1+n)%n,nxt[i]=(i+1)%n;
	if (K==0)
	{
		ll s=0;
		rep(i,1,n-2) s+=S(i,i-1,n-1);
		cout<<s;
		return 0;
	}
	ll l=0,r=1e18,ans=0;
	while (l<=r)
	{
		ll mid=(l+r)>>1;
		if (check(mid)>=K) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}