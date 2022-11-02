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
	#define sz 505050
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
		cout<<(clock()-__t)/1000.0<<'\n';
		#endif
	}
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	ll mul(ll x,ll y){ull s=1.0*x/mod*y;ll res=1ull*x*y-s*mod;return (res%mod+mod)%mod;}
}
using namespace my_std;

int n;
int a[sz];
int pos[sz],cc;
pii p[sz]; int vis[sz];

void work()
{
	read(n); 
	rep(i,1,n) read(a[i]),p[i].fir=-1,p[i].sec=1e9,vis[i]=0; cc=0; rep(i,1,n) if (!a[i]) pos[++cc]=i;
	if (cc<=1) return puts("0"),void();
	int L,R; if (cc&1) L=pos[cc/2],R=pos[cc/2+2]; else L=pos[cc/2],R=pos[cc/2+1];
	rep(i,1,R) if (a[i]) p[a[i]].fir=i; drep(i,n,L) if (a[i]) p[a[i]].sec=i;
	priority_queue<pii>q;
	int cnt1=0,cnt2=0;
	drep(i,R,1)
	{
		if (a[i]) { if (p[a[i]].fir==i) q.push(MP(p[a[i]].sec,a[i])); continue; }
		if (!q.size()) continue;
		pii t=q.top(); q.pop(); ++cnt1,vis[t.sec]=1;
	}
	for (int i=L,cur=0;i<=n;i++) 
		if (a[i]&&!vis[a[i]]&&i==p[a[i]].sec) ++cur;
		else if (!a[i]&&cur) --cur,++cnt2;
	printf("%d\n",min(cnt1+cnt2,cc/2));
}

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	return 0;
}