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
    #define sz 3030
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
struct hh{ll x,y;}p[sz],q[sz];
hh now;
bool cmp(const hh &a,const hh &b){ll u=a.x-now.x,v=b.x-now.x;if (!u||!v) return !u;return 1.0*(a.y-now.y)/u>1.0*(b.y-now.y)/v;}
ll Cross(ll x1,ll y1,ll x2,ll y2){return x1*y2-x2*y1;}

ll C(ll n){return n*(n-1)*(n-2)/6;}

int main()
{
    file();
	read(n);
	rep(i,1,n) read(p[i].x,p[i].y);
	ll ans=0;
	rep(i,1,n)
	{
		rep(j,1,n) if (i!=j) q[j-(j>i)]=p[j];
		now=p[i];
		sort(q+1,q+n,cmp);
		int R=0;
		if (q[1].x==now.x) rep(j,2,n-1) R+=(q[j].x>now.x);
		else rep(j,2,n-1) R+=(q[1].x<now.x)^(Cross(q[1].x-now.x,q[1].y-now.y,q[j].x-now.x,q[j].y-now.y)<0);
		ans+=C(R)+C(n-1-1-R);
		rep(j,2,n-1)
		{
			if (q[j-1].x==now.x) R+=(q[j-1].y<now.y);
			else R+=(q[j-1].x<now.x);
			R-=(q[j].x>now.x);
			ans+=C(R)+C(n-1-1-R);
		}
	}
	ans=1ll*n*(n-1)/2*(n-2)/3*(n-3)*(n-4)/4-ans/2;
	cout<<ans;
	return 0;
}