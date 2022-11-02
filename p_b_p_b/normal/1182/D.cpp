#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
    using namespace std;
    #define pli pair<ll,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define templ template<typename T>
    #define sz 101010
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
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}

ll dn[sz],up[sz];
int son1[sz]; // the only trouble maker
ll W[sz]; // when there is hope
int son[sz];
#define v edge[i].t
void dfs1(int x,int fa)
{
	int cnt=0;
	vector<pli>V;int cc=0,s=0;
	go(x) if (v!=fa)
	{
		dfs1(v,x);++cnt;
		if (dn[v]!=-1) V.push_back(MP(dn[v],v));
		else ++cc,s=v;
	}
	if (cnt==0) return (void)(dn[x]=0,W[x]=son1[x]=-1);
	sort(V.begin(),V.end());
	son[x]=cnt;
	if (cc) dn[x]=-1,son1[x]=s;
	if (cc>1) return (void)(son1[x]=W[x]=-1);
	if (cnt==1)
	{
		if (cc) W[x]=-1;
		else dn[x]=(V[0].fir*sz%mod+1)%mod,W[x]=V[0].fir,son1[x]=-1;
		return;
	}
	if (cc) 
	{
		if (V[0].fir==V[cnt-2].fir) W[x]=V[0].fir;
		else W[x]=-1;
		return;
	}
	if (V[0].fir==V[cnt-1].fir) dn[x]=((W[x]=V[0].fir)*sz%mod+cnt)%mod,son1[x]=-1;
	else if (V[0].fir==V[cnt-2].fir) dn[x]=-1,W[x]=V[0].fir,son1[x]=V[cnt-1].sec;
	else if (V[1].fir==V[cnt-1].fir) dn[x]=-1,W[x]=V[1].fir,son1[x]=V[0].sec;
	else dn[x]=W[x]=son1[x]=-1;
}
void dfs2(int x,int fa)
{
	go(x) if (v!=fa)
	{
		if (son[x]==1)
		{
			if (x==1) up[v]=0;
			else if (up[x]==-1) up[v]=-1;
			else up[v]=(up[x]*sz%mod+1)%mod;
		}
		else if (dn[x]!=-1||son1[x]==v)
		{
			if (x==1) up[v]=(W[x]*sz%mod+son[x]-1)%mod;
			else if (up[x]==W[x]&&up[x]!=-1) up[v]=(W[x]*sz%mod+son[x])%mod;
			else up[v]=-1;
		}
		else if (son[x]==2)
		{
			ll w=dn[son1[x]];
			if (w==-1) up[v]=-1;
			else if (x==1) up[v]=(w*sz%mod+1)%mod;
			else if (w==up[x]) up[v]=(w*sz%mod+2)%mod;
			else up[v]=-1;
		}
		else up[v]=-1;
		dfs2(v,x);
	}
}

int main()
{
    file();
	read(n);
	if (n<=3) return puts("1"),0; 
	int x,y;
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs1(1,0);
	rep(i,1,n) up[i]=-1;
	dfs2(1,0);
	if (dn[1]!=-1) return puts("1"),0;
	rep(i,2,n) if (up[i]==W[i]&&dn[i]!=-1&&son[i]) return printf("%d",i),0;
	rep(i,2,n) if (!son[i]&&up[i]!=-1) return printf("%d",i),0;
	puts("-1");
	return 0;
}
// ntf ak ioi