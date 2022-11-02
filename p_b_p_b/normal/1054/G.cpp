#include<bits/stdc++.h>
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif
using namespace std;
namespace my_std{
 
int64_t cpu_time_calls = 0;
 
long double cpu_time() {
    cpu_time_calls++;
 
#if defined(_WIN32) || defined(_WIN64)
    FILETIME creation_ft, exit_ft, kernel_ft, user_ft;
    GetProcessTimes(GetCurrentProcess(), &creation_ft, &exit_ft, &kernel_ft, &user_ft);
 
    auto extract_time = [](FILETIME ft) {
        return 1e-7L * (ft.dwLowDateTime | uint64_t(ft.dwHighDateTime) << 32);
    };
 
    return extract_time(user_ft) + extract_time(kernel_ft);
#else
    return (long double) clock() / CLOCKS_PER_SEC;
#endif
}
//	using namespace std;
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
	#define sz 2222
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

int n,m;
bitset<sz>S[sz];

int del[sz];
pii e[sz];
int _lk[sz][sz]; bitset<sz>_s[sz],bel[sz],tmp;

void sol()
{
	int N=0;
	rep(i,1,n) if (!del[i]) ++N;
	#define s _s[N]
	rep(i,1,n) if (!del[i]) s[i]=1;
	assert(N!=1);
	if (N==2) { int x=s._Find_first(); s[x]=0; int y=s._Find_first(); e[1]=MP(x,y); return; }
	int _c=N; rep(i,1,m) { int __; tmp=s&S[i]; if ((__=tmp.count())>1) s=tmp,_c=__; if (_c==2) break; }
	vector<int>V; rep(i,1,n) if (s[i]) V.push_back(i);
	int M=s.count();
	if (M==N) { rep(i,1,M-1) e[i]=MP(V[i],V[i-1]); return; }
	rep(i,1,M-1) del[V[i]]=1;
	for (auto x:V) bel[x].reset();
	rep(i,1,m)
	{
		int c=0;
		if (M>10) { tmp=S[i]&s; c=tmp.count(); } else for (auto x:V) c+=S[i][x];
		if (c!=1) { for (auto x:V) S[i][x]=0; if (c) S[i][V[0]]=1; continue; }
		int x=0; if (M>10) x=tmp._Find_first(); else for (auto t:V) if (S[i][t]) x=t;
		bel[x]|=S[i]; S[i][x]=0,S[i][V[0]]=1;
	}
	int *lk=_lk[N],flg=0; auto add=[&](int x,int w){if (lk[x]) flg=1;lk[x]=w;};
	for (auto x:V) rep(i,1,n) if (bel[x][i]&&i!=x) add(i,x);
	if (flg) return e[1].fir=-1,void();
	rep(i,1,n) if (!lk[i]) lk[i]=V[0];
	sol(); if (e[1].fir==-1) return;
	rep(i,1,N-M) { int &x=e[i].fir,&y=e[i].sec; if (y==V[0]) swap(x,y); if (x==V[0]) x=lk[y]; }
	rep(i,1,M-1) e[N-M+i]=MP(V[i-1],V[i]);
	#undef s
}

void work()
{
	read(n,m);
	rep(i,1,m)
	{
		static char s[sz]; scanf("%s",s+1);
		rep(j,1,n) S[i][j]=s[j]-'0';
	}
	if (n==1) return puts("YES"),void();
	sol();
	if (e[1].fir==-1) puts("NO");
	else { puts("YES"); rep(i,1,n-1) printf("%d %d\n",e[i].fir,e[i].sec); }
	rep(i,1,m) S[i].reset();
	rep(i,1,n) del[i]=0,bel[i].reset(),_s[i].reset();
	rep(i,1,n) rep(j,1,n) _lk[i][j]=0;
}

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	chktime();
	return 0;
}