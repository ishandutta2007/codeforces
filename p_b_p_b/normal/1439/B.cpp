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
	typedef unsigned long long ull;
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

int n,m,K;
vector<int>V[sz];
int deg[sz],del[sz];

const int mod=19260817; const ull B=2384728977;
pii w[mod]; int vis[mod],cc;
void Add(int x,int y)
{
	if (x>y) swap(x,y);
	ull k=1ull*x*(n+1)+y+B*x+B*B*B*y; k=k^((x*B)<<10)^((y*B*B)>>3); k%=mod;
	while (w[k].fir) { ++k; if (k==mod) k=0; }
	w[k]=MP(x,y); vis[cc++]=k;
}
int check(int x,int y)
{
	if (x>y) swap(x,y);
	ull k=1ull*x*(n+1)+y+B*x+B*B*B*y; k=k^((x*B)<<10)^((y*B*B)>>3); k%=mod;
	while (w[k].fir&&w[k]!=MP(x,y)) { ++k; if (k==mod) k=0; }
	return w[k]==MP(x,y);
}


void work()
{
	read(n,m,K);
	rep(i,1,n) deg[i]=del[i]=0,V[i].clear();
	rep(i,0,cc-1) w[vis[i]]=pii(); cc=0;
	int x,y;
	rep(i,1,m) read(x,y),V[x].push_back(y),V[y].push_back(x),++deg[x],++deg[y],Add(x,y);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	rep(i,1,n) q.push(MP(deg[i],i));
	int cur=m;
	while (!q.empty())
	{
		pii p=q.top(); q.pop();
		int x=p.sec,d=p.fir; if (del[x]) continue;
		del[x]=1;
		if (d>=K)
		{
			vector<int>ans; ans.push_back(x);
			rep(i,1,n) if (!del[i]) ans.push_back(i);
			printf("1 %d\n",(int)ans.size());
			for (auto x:ans) printf("%d ",x); return puts(""),void();
		}
		if (d==K-1&&1ll*K*(K-1)/2<=cur)
		{
			vector<int>ans; ans.push_back(x);
			for (auto y:V[x]) if (!del[y]) ans.push_back(y); random_shuffle(ans.begin(),ans.end());
			int flg=1;
			rep(i,0,(int)ans.size()-1) rep(j,i+1,(int)ans.size()-1) if (!check(ans[i],ans[j])) { flg=0; break; }
			if (flg) { puts("2"); for (auto x:ans) printf("%d ",x); puts(""); return; }
		}
		for (auto y:V[x]) if (!del[y]) --deg[y],--cur,q.push(MP(deg[y],y));
	}
	puts("-1");
}

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	return 0;
}