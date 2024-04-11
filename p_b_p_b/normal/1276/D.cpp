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
    #define sz 202020
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
        #ifndef ONLINE_JUDGE
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
 
int n;
vector<pii>V[sz];
 
ll f[sz],g[sz],h[sz];
ll pref[sz],sufg[sz],W[sz];
void dfs(int x,int fa,int fid)
{
	#define v V[x][i].sec
	int m=V[x].size();--m;
	rep(i,1,m) if (v!=fa) dfs(v,x,V[x][i].fir);
	pref[0]=sufg[m+1]=1;
	rep(i,1,m) if (v!=fa) pref[i]=pref[i-1]*f[V[x][i].sec]%mod; else pref[i]=pref[i-1];
	drep(i,m,1) if (v!=fa) sufg[i]=sufg[i+1]*g[V[x][i].sec]%mod; else sufg[i]=sufg[i+1];
	rep(i,1,m) if (v!=fa) W[i]=pref[i-1]*h[v]%mod*sufg[i+1]%mod;
	
	// g
	rep(i,1,m) if (v!=fa) (g[x]+=W[i])%=mod; (g[x]+=pref[m])%=mod;
	
	// f
	rep(i,1,m) if (v==fa) { f[x]=pref[i-1]*sufg[i+1]%mod; break; }
	rep(i,1,m) if (V[x][i].fir<fid) (f[x]+=W[i])%=mod;
	
	// h
	rep(i,1,m) if (V[x][i].fir>fid) (h[x]+=W[i])%=mod;
	(h[x]+=pref[m])%=mod;
}
 
int main()
{
    file();
	int x,y;
	read(n);
	rep(i,1,n) V[i].push_back(MP(0,0));
	rep(i,1,n-1) read(x,y),V[x].push_back(MP(i,y)),V[y].push_back(MP(i,x));
	dfs(1,0,0);
	cout<<g[1];
	return 0;
}