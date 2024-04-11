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
    #define sz 101010
    typedef long long ll;
    typedef long double db;
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
 
const db eps=1e-9;
 
int n,m;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}
 
int dfn[sz],top[sz],son[sz],size[sz],fa[sz],dep[sz],cnt;
#define v edge[i].t
void dfs1(int x,int fa)
{
	dep[x]=dep[::fa[x]=fa]+1;size[x]=1;
	go(x) if (v!=fa)
	{
		dfs1(v,x);
		size[x]+=size[v];
		if (size[v]>size[son[x]]) son[x]=v;
	}
}
void dfs2(int x,int fa,int tp)
{
	dfn[x]=++cnt;top[x]=tp;
	if (son[x]) dfs2(son[x],x,tp);
	go(x) if (v!=fa&&v!=son[x]) dfs2(v,x,v); 
}
#undef v
 
#define I inline 
I int dcmp(db x){return fabs(x)<=eps?0:(x>0?1:-1);}
struct Vector
{
    db x,y;
    Vector(db xx=0,db yy=0){x=xx,y=yy;}
    I const Vector operator + (const Vector &a) const {return Vector(x+a.x,y+a.y);}
    I const Vector operator - (const Vector &a) const {return Vector(x-a.x,y-a.y);}
    I const Vector operator * (const db &a) const {return Vector(x*a,y*a);}
    I const Vector operator / (const db &a) const {return Vector(x/a,y/a);}
    I const bool operator < (const Vector &a) const {return dcmp(x-a.x)==0?dcmp(y-a.y)<0:dcmp(x-a.x)<0;}
    I const bool operator == (const Vector &a) const {return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;}
    I const bool operator != (const Vector &a) const {return dcmp(x-a.x)!=0||dcmp(y-a.y)!=0;}
};
typedef Vector Point;
I db Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
I db Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
I db Len(Vector a){return sqrt(Dot(a,a));}
struct Line
{
    Point a,b;
    Line(){}
    Line(Point aa,Point bb){a=aa,b=bb;}
};
vector<Line>vec[sz];
struct hhh
{
	db x;int id,type;
	const bool operator < (const hhh &a) const 
	{
		if (dcmp(x-a.x)) return x<a.x;
		return type<a.type;
	}
}ss[sz*20];
typedef Line seg;
I bool OnSeg(Point p,seg x){Point a=x.a,b=x.b;return dcmp(Cross(p-a,a-b))==0&&dcmp(Dot(p-a,p-b))<=0;}
I Point LI(Line l1,Line l2)
{
    Vector v=l1.a-l2.a,v1=l1.b-l1.a,v2=l2.b-l2.a;
    db t=Cross(v,v2)/Cross(v2,v1);
    return l1.a+v1*t;
}
I bool LSI(Line l,Point a,Point b)
{
    Vector v=l.b-l.a,v1=a-l.a,v2=b-l.a;
    return dcmp(Cross(v,v1))!=dcmp(Cross(v,v2));
}
I db SSI(seg l1,seg l2)
{
	db ret=1e9;
	if (OnSeg(l1.a,l2)) chkmin(ret,l1.a.x);
	if (OnSeg(l1.b,l2)) chkmin(ret,l1.b.x);
	if (OnSeg(l2.a,l1)) chkmin(ret,l2.a.x);
	if (OnSeg(l2.b,l1)) chkmin(ret,l2.b.x);
	if (ret<1e9) return ret;
	if (!LSI(l1,l2.a,l2.b)||!LSI(l2,l1.a,l1.b)) return 1e9;	
	return LI(l1,l2).x;
}
 
int lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]>dep[y]?y:x;
}
void add(int x,int y,db T,db V)
{
	V=1.0/V;
	int l=lca(x,y);db Len=dep[y]-dep[l];
	while (top[x]!=top[l])
	{
		db len=dep[x]-dep[top[x]]+1;
		vec[top[x]].push_back(seg(Point(T,dfn[x]),Point(T+len*V,dfn[top[x]]-1)));
		x=fa[top[x]];T+=len*V;
	}
	db len=dep[x]-dep[l];
	if (x!=l) vec[top[x]].push_back(seg(Point(T,dfn[x]),Point(T+len*V,dfn[l])));T+=len*V;
	while (top[y]!=top[l])
	{
		db len=dep[y]-dep[top[y]]+1;Len-=len;
		vec[top[y]].push_back(seg(Point(T+Len*V,dfn[top[y]]-1),Point(T+len*V+Len*V,dfn[y])));
		y=fa[top[y]];
	}
	len=dep[y]-dep[l];
	if (y!=l) vec[top[y]].push_back(seg(Point(T,dfn[l]),Point(T+len*V,dfn[y])));
	if (x==l&&y==l) vec[top[l]].push_back(seg(Point(T,dfn[l]),Point(T,dfn[l])));
}
 
vector<seg>s;
db T;
struct cmp
{
	const bool operator () (const int &x,const int &y) const
	{
		seg l1=s[x],l2=s[y];
		db y1;
		if (dcmp(l1.b.x-l1.a.x)) y1=(l1.a+(l1.b-l1.a)*(T-l1.a.x)/(l1.b.x-l1.a.x)).y;
		else y1=l1.a.y;
		db y2;
		if (dcmp(l2.b.x-l2.a.x)) y2=(l2.a+(l2.b-l2.a)*(T-l2.a.x)/(l2.b.x-l2.a.x)).y;	
		else y2=l2.a.y;
		return y1<y2;
	}
};
set<int,cmp>S;
db ans=1e9;
void work()
{
	db ans=1e9;
	int M=s.size();s.push_back(seg(Point(),Point()));
	rep(i,0,M-1) ss[i*2]=(hhh){s[i].a.x,i,0},ss[i*2+1]=(hhh){s[i].b.x,i,1};
	sort(ss,ss+M+M);
	rep(i,0,M+M-1)
	{
		if (ss[i].x>ans) break;
		if (ss[i].type)
		{
			auto it=S.find(ss[i].id);
			if (it!=S.begin()&&next(it)!=S.end()) chkmin(ans,SSI(s[*prev(it)],s[*next(it)]));
			S.erase(ss[i].id);
		}
		else
		{
			T=ss[i].x;
			s[M]=seg(Point(T,s[ss[i].id].a.y),Point(T,s[ss[i].id].a.y));
			if (S.find(M)!=S.end()) {ans=T;break;}
			auto it=S.insert(ss[i].id).fir;
			if (it!=S.begin()) chkmin(ans,SSI(s[*it],s[*prev(it)]));
			if (next(it)!=S.end()) chkmin(ans,SSI(s[*it],s[*next(it)]));
		}
	}
	chkmin(::ans,ans);
	S.clear();
}
 
int main()
{
    file();
	read(n,m);
	int x,y;
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs1(1,0),dfs2(1,0,1);
	while (m--)
	{
		int v,t;read(t,v,x,y);
		add(x,y,t,v);
	}
	rep(i,1,n) if (top[i]==i) s=vec[i],work();
	if (ans<1e9) cout<<setprecision(20)<<fixed<<ans;
	else puts("-1");
	return 0;
}
// thank goodness that it finally got accepted