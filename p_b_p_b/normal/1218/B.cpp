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
    typedef double db;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
    templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
    templ inline bool chkmin(T &x,T y){return !(x<y)?x=y,1:0;}
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

#define eps 1e-8
int dcmp(db x){return fabs(x)<eps?0:(x>0?1:-1);}
struct Point
{
	db x,y;int id;
	Point(db X=0,db Y=0,int I=0){x=X,y=Y,id=I;}
	const Point operator + (const Point &a) const {return Point(x+a.x,y+a.y);}
	const Point operator - (const Point &a) const {return Point(x-a.x,y-a.y);}
	const Point operator * (const db &a) const {return Point(x*a,y*a,id);}
//	const Point operator / (const db &a) const {return Point(x/a,y/a);}
	const bool operator < (const Point &a) const {return atan2(y,x)<atan2(a.y,a.x);}
};
typedef Point Vector;
db Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
db Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Vector Rot(Vector a,db x){return Vector(a.x*cos(x)-a.y*sin(x),a.y*cos(x)+a.x*sin(x),a.id);}
db Area(Point a,Point b,Point c){return fabs(Cross(b-a,c-a))/2;}
db Len(Vector a){return sqrt(Dot(a,a));}
struct Line{Point a,b;Line(Point A,Point B){a=A,b=B;}};
Point LI(Line l1,Line l2)
{
//	assert(dcmp(l1.a.x-l1.b.x));assert(dcmp(l2.a.x-l2.b.x));
	db k1=dcmp(l1.a.x-l1.b.x)?(l1.a.y-l1.b.y)/(l1.a.x-l1.b.x):1e18,b1=l1.a.y-l1.a.x*k1;
	db k2=dcmp(l2.a.x-l2.b.x)?(l2.a.y-l2.b.y)/(l2.a.x-l2.b.x):1e18,b2=l2.a.y-l2.a.x*k2;
	if (!dcmp(k1-k2))
	{
		if (dcmp(b1-b2)) return Point(1e18,1e18);
		if (dcmp(Dot(l1.a-l2.a,l1.a-l2.b))<=0) return l1.a;
		return l1.b;
	}
	if (k1>1e17) return Point(l1.a.x,k2*l1.a.x+b2);
	if (k2>1e17) return Point(l2.a.x,k1*l2.a.x+b1);
	db x=(b2-b1)/(k1-k2),y=k1*x+b1;
	return Point(x,y);
}
bool SSI(Line l1,Line l2){Point a=LI(l1,l2);return dcmp(Dot(a-l2.a,a-l2.b))<=0&&dcmp(Dot(a-l1.a,a-l1.b))<=0;}
bool check(Point a,Point b,Point c){return dcmp(Area(a,b,c))==0;}

int n,m;
Point p[sz];
vector<Point>poly[sz],up[sz],dn[sz];vector<db>Up[sz],Dn[sz];Point L[sz],R[sz];
int p1[sz],p2[sz];Point c1[sz],c2[sz];
Point cur;
void Maintain(int i)
{
	while (!SSI(Line(Point(0,0),cur),Line(up[i][p1[i]],up[i][p1[i]+1]))) ++p1[i];
	while (!SSI(Line(Point(0,0),cur),Line(dn[i][p2[i]],dn[i][p2[i]+1]))) ++p2[i];
	c1[i]=LI(Line(Point(0,0),cur),Line(up[i][p1[i]],up[i][p1[i]+1]));
	c2[i]=LI(Line(Point(0,0),cur),Line(dn[i][p2[i]],dn[i][p2[i]+1]));
	if (check(Point(0,0),cur*1e-5,L[i])) p1[i]=p2[i]=0,c1[i]=c2[i]=L[i];
	else if (check(Point(0,0),cur*1e-5,R[i])) p1[i]=(int)up[i].size()-2,p2[i]=(int)dn[i].size()-2,c1[i]=c2[i]=R[i];
}
db calc(int id){return Up[id][p1[id]]+Dn[id][p2[id]]+Area(L[id],c1[id],up[id][p1[id]])+Area(L[id],c2[id],dn[id][p2[id]])+Area(L[id],c1[id],c2[id]);}

struct cmp
{
	const bool operator ()(const int &x,const int &y)
	{
		Point a=LI(Line(Point(0,0),cur),Line(L[x],R[x])),b=LI(Line(Point(0,0),cur),Line(L[y],R[y]));
		return Dot(a,a)<Dot(b,b);
	}
};
set<int,cmp>s;

int main()
{
    file();
	read(n);
	rep(i,1,n)
	{
		int k;read(k);int x,y;
		rep(j,1,k) read(x,y),poly[i].push_back(p[++m]=Point(x,y,i));
	}
	rep(i,1,m) p[i]=Rot(p[i],1.9260817);
	rep(i,1,n) for (auto &x:poly[i]) x=Rot(x,1.9260817);
	sort(p+1,p+m+1);
	rep(i,1,n)
	{
		int s=poly[i].size();
		Point mx=poly[i][0],mn=poly[i][0];
//		for (auto a:poly[i]) printf("%.5lf %.5lf\n",a.x,a.y);
		int pmx=0,pmn=0;
		rep(j,0,s-1) { if (chkmax(mx,poly[i][j])) pmx=j; if (chkmin(mn,poly[i][j])) pmn=j; }
		if (dcmp(Cross(mx,mn))>0)
		{
			swap(mn,mx);swap(pmn,pmx);
			rep(j,0,s-1) if (atan2(poly[i][j].y,poly[i][j].x)>0&&chkmin(mn,poly[i][j])) pmn=j;
			rep(j,0,s-1) if (atan2(poly[i][j].y,poly[i][j].x)<0&&chkmax(mx,poly[i][j])) pmx=j;
		}
		vector<Point>tmp;rep(j,0,s-1) tmp.push_back(poly[i][(j+pmn)%s]);poly[i]=tmp;tmp.push_back(mn);
		(pmx+=s-pmn)%=s;pmn=0;
		rep(j,0,pmx) up[i].push_back(tmp[j]);
		drep(j,s,pmx) dn[i].push_back(tmp[j]);
		int s1=up[i].size(),s2=dn[i].size();
		Up[i].push_back(0),Dn[i].push_back(0);
		rep(j,1,s1-1) Up[i].push_back(Area(up[i][j-1],up[i][j],mn));
		rep(j,1,s2-1) Dn[i].push_back(Area(dn[i][j-1],dn[i][j],mn));
		rep(j,1,s1-1) Up[i][j]+=Up[i][j-1];
		rep(j,1,s2-1) Dn[i][j]+=Dn[i][j-1];
		L[i]=mn,R[i]=mx;
	}
	cur=Point(-1e9,0);
	rep(i,1,n)
	{
		if (!SSI(Line(Point(0,0),cur),Line(L[i],R[i]))) continue;
		s.insert(i);
		Maintain(i);
	}
	p[++m]=cur;
	db ans=0;
	rep(k,1,m)
	{
		int i=p[k].id;cur=p[k]*1e5;
		if (fabs(Len(p[k]-L[i]))&&fabs(Len(p[k]-R[i]))&&(k!=m||!s.size())) continue;
		if (k!=m&&!fabs(Len(p[k]-L[i])))
		{
			Maintain(i);
			if (!s.size()) { s.insert(i); continue; }
			int beg=*(s.begin());
			s.insert(i);
			if (*(s.begin())!=i) continue;
			i=beg;
			db S1=calc(i);
			Maintain(i);
			db S2=calc(i);
			ans+=S2-S1;
		}
		else
		{
			if (k==m) i=*(s.begin());
			if (k!=m&&i!=*(s.begin())) { s.erase(i); p1[i]=p2[i]=0; continue; }
			s.erase(i);
			db S1=calc(i);
			Maintain(i);
			db S2=calc(i);
			ans+=S2-S1;p1[i]=p2[i]=0;
			if (s.size()) Maintain(*(s.begin()));
		}
	}
	printf("%.10lf",ans);
	return 0;
}