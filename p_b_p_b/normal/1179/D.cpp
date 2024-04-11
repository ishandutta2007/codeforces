#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
    using namespace std;
    #define pil pair<int,ll>
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

ll dp[sz];
int size[sz];
ll ans=1e18;
#define v edge[i].t
#define Sqr(x) (1ll*(x)*(x))
inline db K(pil a,pil b){return 1.0*(b.sec-a.sec)/(b.fir-a.fir);}
void dfs(int x,int fa)
{
	vector<pil>V;size[x]=1;
	go(x) if (v!=fa)
	{
		dfs(v,x);
		V.push_back(MP(size[v],dp[v]-2ll*n*size[v]+Sqr(size[v])));
		size[x]+=size[v];
	}
	dp[x]=Sqr(size[x]);
	go(x) if (v!=fa) chkmin(dp[x],dp[v]+Sqr(size[x]-size[v]));
	if (!V.size()) return;
	sort(V.begin(),V.end());
	vector<pil>con;con.push_back(V[0]);int top=0;
	rep(i,1,(int)V.size()-1) 
	{
		while (top&&K(con[top],con[top-1])>-2*V[i].fir) --top,con.pop_back();
		chkmin(ans,con[top].sec+V[i].sec+2ll*con[top].fir*V[i].fir+Sqr(n));
		if (V[i].fir==V[i-1].fir) continue;
		while (top&&K(con[top],con[top-1])>=K(con[top-1],V[i])) --top,con.pop_back();
		con.push_back(V[i]);++top;
	}
}

int main()
{
    file();
	int x,y;
	read(n);
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs(1,0);chkmin(ans,dp[1]);
	ll Ans=(Sqr(n)-ans)/2+1ll*n*(n-1)/2;
	cout<<Ans;
	return 0;
}