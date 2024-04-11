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
    #define sz 30100
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

int n,K;
vector<int>bl[sz];
int ok[sz];

struct hh{int t,nxt;}edge[sz];
int head[sz],ecnt;
void make_edge(int f,int t){edge[++ecnt]=(hh){t,head[f]};head[f]=ecnt;}
int vis[sz];

int pth[sz],c;
void dfs(int x){for (int &i=head[x],t;(t=i);i=edge[i].nxt) if (!vis[i]) vis[i]=1,dfs(edge[i].t),pth[++c]=edge[t].t;}

int ask(int x){printf("? %d\n",x);fflush(stdout);char c;cin>>c;return c=='Y';}
void add(int id,int flg){rep(i,0,K-1) ok[bl[id][i]]&=!(flg&ask(bl[id][i]));}
void add2(int id,int flg)
{
	int p=-1;
	drep(i,K-1,0) if (ok[bl[id][i]]) p=i;
	if (p==-1) { rep(i,0,K-1) ask(bl[id][i]); return; }
	if (p==0) { rep(i,0,K-1) if (ok[bl[id][i]]) ok[bl[id][i]]&=!(flg&ask(bl[id][i])); else ask(bl[id][p]); }
	else
	{
		ok[bl[id][p]]&=!(flg&ask(bl[id][p]));
		rep(i,1,p) ask(bl[id][p]);
		rep(i,p+1,K-1) if (ok[bl[id][i]]) ok[bl[id][i]]&=!(flg&ask(bl[id][i])); else ask(bl[id][p]);
	}
}

void work(int t)
{
	int n=::n/K;
	rep(i,1,n) rep(j,i+1,n) make_edge(i,j);
	rep(i,1,n/2) rep(j,1,n-2*i+1) make_edge(n-i+1,i);
	dfs(1);
	pth[++c]=1;reverse(pth+1,pth+c+1);--c;
	add(1,!t);
	rep(i,2,c) t?add2(pth[i],pth[i]>pth[i-1]):add(pth[i],pth[i]>pth[i-1]);
	rep(i,1,ecnt) vis[i]=0;c=ecnt=0;rep(i,1,n) head[i]=0;
}

int main()
{
//    file();
	read(n,K);
	rep(i,1,n) ok[i]=1;
	rep(i,1,n/K) rep(j,(i-1)*K+1,i*K) bl[i].push_back(j);
	work(0);
	rep(i,1,n/K) reverse(bl[i].begin(),bl[i].end());
	if (K!=n) work(1);
	int ans=0;
	rep(i,1,n) ans+=ok[i];
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}