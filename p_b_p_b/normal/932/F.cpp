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
    #define sz 101001
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
ll a[sz],b[sz];
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}

struct Point
{
	ll x,y;
	Point(ll X=0,ll Y=0){ x=X,y=Y; }
	const bool operator < (const Point &a) const {return x<a.x;}
	const Point operator + (const Point &a) const {return Point(x+a.x,y+a.y);}
	const Point operator - (const Point &a) const {return Point(x-a.x,y-a.y);}
};
long double Cross(Point a,Point b){return (long double)b.y*a.x-(long double)a.y*b.x;}

ll dp[sz];
set<Point>con[sz];
#define conv con[id]
void insert(int id,Point a)
{
	auto it=conv.lower_bound(a);
	if (it!=conv.end()&&(*it).x==a.x) { if ((*it).y<=a.y) return; conv.erase(it++); }
	if (it!=conv.begin()&&it!=conv.end()&&Cross(a-*prev(it),*it-*prev(it))<=0) return;
	while (233)
	{
		if (it==conv.end()||next(it)==conv.end()) break;
		auto i1=it,i2=next(it);
		auto p1=*i1,p2=*i2;
		if (Cross(p2-a,p1-a)>=0) conv.erase(it++);
		else break;
	}
	if (it==conv.begin()) return (void)(conv.insert(a));
	--it;
	while (233)
	{
		if (it==conv.begin()) break;
		auto i1=it,i2=prev(it);
		auto p1=*i1,p2=*i2;
		if (Cross(a-p2,p1-p2)>=0) conv.erase(it--);
		else break;
	}
	conv.insert(a);
}
ll calc(Point a,ll k){return a.y-k*a.x;}
ll query(int id,ll k)
{
	ll ret=1e18;
	if (conv.size()<=5) { for (auto a:conv) chkmin(ret,calc(a,k)); return ret; }
	ll l=-1e6,r=1e6;
	while (l<=r)
	{
		ll mid=(l+r)/2;
		auto it=conv.lower_bound(Point(mid,0));
		if (it==conv.end()) { r=mid-1; continue; }
		chkmin(ret,calc(*it,k));
		if (next(it)==conv.end()) { r=mid-1; continue; }
		auto itt=next(it);
		if ((*itt).y-(*it).y>=k*((*itt).x-(*it).x)) r=mid-1;
		else l=mid+1;
	}
	return ret;
}
#undef conv
int rt[sz];
#define v edge[i].t
void dfs(int x,int fa)
{
	go(x) if (v!=fa)
	{
		dfs(v,x);
		if (!rt[x]) { rt[x]=rt[v]; continue; }
		if (con[rt[x]].size()<con[rt[v]].size()) swap(rt[x],rt[v]);
		for (auto w:con[rt[v]]) insert(rt[x],w);
	}
	if (rt[x]) dp[x]=query(rt[x],-a[x]);
	else rt[x]=x;
	insert(rt[x],(Point){b[x],dp[x]});
}

int main()
{
    file();
	read(n);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) read(b[i]);
	int x,y;
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs(1,0);
	rep(i,1,n) printf("%I64d ",dp[i]);
	return 0;
}