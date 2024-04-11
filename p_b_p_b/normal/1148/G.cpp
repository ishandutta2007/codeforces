// **** $k$ 
//  $k$ 
// 
//  $k$ 
//  1  $k$ 
//  1 
// 
// /kk
// 
//  0  unfair  $\ge k$ 
//  $f(r)$  $r$  0 
//  $c$  $f(c-1)+3<k\le f(c)+3$ 
//  $c-1$  $f(c)-f(c-1)-1$  $c$  $c$  0  $c$  $k$  $k+1$ 
//  $k+1$ 
//  $f(r)$  $\mu(x)$  0 
#include<bits/stdc++.h>
clock_t t=clock();
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
	#define sz 10101010
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
		cout<<(clock()-t)/1000.0<<'\n';
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

int pri[sz],mu[sz],cc;
int npri[sz];
void init()
{
	mu[1]=1;
	rep(i,2,sz-1)
	{
		if (!npri[i]) pri[++cc]=i,mu[i]=-1;
		rep(j,1,cc)
		{
			int x=i*pri[j];
			if (x>=sz) break;
			npri[x]=1;
			if (i%pri[j]==0) break;
			mu[x]=-mu[i];
		}
	}
}

int n,K;
int a[sz];
int vis[sz];
vector<int>p[sz];

int cnt[10101010],m;
void add(int i,int tp) { m+=tp; int S=1<<p[i].size(); rep(s,0,S-1) { int tmp=1; rep(j,0,(int)p[i].size()-1) if (s>>j&1) tmp*=p[i][j]; cnt[tmp]+=tp; } }
void work(int R,int tp){rep(i,1,R) if (!vis[i]) add(i,tp);}
int deg(int i)
{
	int res=0,S=1<<p[i].size();
	rep(s,1,S-1) { int tmp=1; rep(j,0,(int)p[i].size()-1) if (s>>j&1) tmp*=p[i][j]; 
	res-=mu[tmp]*cnt[tmp]; }
	return m-res;
}

int tri[3];

int main()
{
	file();
	init();
	read(n,K);
	rep(i,1,n)
	{
		read(a[i]);int x=a[i];
		rep(j,1,cc) 
			if (1ll*pri[j]*pri[j]<=x)
				{ if (x%pri[j]==0) for (p[i].push_back(pri[j]);x%pri[j]==0;x/=pri[j]); }
			else break;
		if (x!=1) p[i].push_back(x);
	}
	work(n,1);
	rep(i,1,n) if (deg(i)>=2)
	{
		tri[0]=i;int c=1;
		rep(j,1,n) if (c<=2&&__gcd(a[j],a[i])==1) tri[c]=j,++c;
		break; 
	}
	if (!tri[0])
	{
		work(n,-1);
		rep(i,1,n) if (K)
		{
			if (!deg(i)) printf("%d ",i),--K;
			add(i,1);
		}
		return 0;
	}
	rep(i,0,2) vis[tri[i]]=1,add(tri[i],-1);
	int c2=0;
	rep(i,1,n) if (!deg(i)) vis[i]=2,++c2;
	if (c2>=K) { rep(i,1,n) if (K&&vis[i]==2) printf("%d ",i),--K; return 0; }
	if (K==3) { rep(i,0,2) printf("%d ",tri[i]); return 0; }
	rep(i,1,n) if (vis[i]!=1) add(i,-1);
	int l=1,r=n,c=1;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		work(mid,1); int cc=0;
		rep(i,1,mid) if (!vis[i]) cc+=!!deg(i);
		if (cc+3>=K) c=mid,r=mid-1; else l=mid+1;
		work(mid,-1);
	}
	work(c-1,1);
	vector<int>ans;
	rep(i,1,c-1) if (deg(i)&&!vis[i]) ans.push_back(i);
	rep(i,1,c-1) if (!vis[i]&&!deg(i)&&__gcd(a[i],a[c])==1&&(int)ans.size()+3<K) ans.push_back(i);
	ans.push_back(c);
	K-=(int)ans.size()+1;
	rep(i,0,K) ans.push_back(tri[i]);
	for (auto x:ans) printf("%d ",x);
	return 0;
}