#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;
typedef std::pair<ll,ll> pll;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 1000011,LIM = 100000;
bool is_zero(double x){return x<1e-7&&-x<1e-7?1:0;}
struct Vec
{
	double x,y;
	Vec():x(0),y(0) {}
	Vec(double x,double y):x(x),y(y){}
	Vec operator+ (Vec you){return Vec(x+you.x,y+you.y);}
	Vec operator- (Vec you){return Vec(x-you.x,y-you.y);}
	Vec rotate_90(){return Vec(-y,x);}
	double length(){return sqrt(x*x+y*y);}
};
Vec operator* (Vec a,double k){return Vec(a.x*k,a.y*k);}
Vec operator* (double k,Vec a){return Vec(a.x*k,a.y*k);}
double cross(Vec a,Vec b){return a.x*b.y-b.x*a.y;}
double dot(Vec a,Vec b){return a.x*b.x+a.y*b.y;}
struct Line
{
	Vec s,v;
	Line(){}
	Line(Vec s,Vec v):s(s),v(v) {}
};
Line Seg_to_Line(Vec a,Vec b){return Line{a,b-a};}
Vec intersection(Line a,Line b)
{
	double AP=cross(b.s-a.s,b.v),BP=cross(a.s+a.v-b.s,b.v);
	return a.s+a.v*(AP/(AP+BP));
}
Vec a[MAXN],b[MAXN],v[MAXN];
inline bool cmpArg(Vec a,Vec b)
{
	//printf("Compare (%.0lf,%.0lf) with (%.0lf,%.0lf)\n",a.x,a.y,b.x,b.y);
	if(is_zero(cross(a,b)))
	{
		return is_zero(a.x-b.x)?a.y>b.y:a.x<b.x;
	}
	return cross(a,b)<0;
}
double get_circle(Vec a,Vec b,Vec c)
{
	//printf("Get cir (%.2lf,%.2lf) (%.2lf,%.2lf) (%.2lf,%.2lf)\n",a.x,a.y,b.x,b.y,c.x,c.y);
	Line L1((a+b)*0.5,(a-b).rotate_90()),L2((a+c)*0.5,(a-c).rotate_90());

	Vec p(intersection(L1,L2));
	//printf("(%.2lf,%.2lf)\n",p.x,p.y);
	return (p-a).length();
}

struct VecInt
{
	int x,y;
	VecInt(){}
	VecInt(int x,int y):x(x),y(y) {}
	inline VecInt operator+ (const VecInt& you)const{return VecInt(x+you.x,y+you.y);}
	inline VecInt operator- (const VecInt& you)const{return VecInt(x-you.x,y-you.y);}
}st[MAXN];
inline Vec ToVec(const VecInt& a){return Vec(a.x,a.y);}
inline ll cross(const VecInt& a,const VecInt& b){return ll(a.x)*b.y-ll(b.x)*a.y;}
int main()
{
	int n=read(),top,len=0;
	for(int i=1;i<=n;++i)
	{
		int pre=len;
		int x=read(),y=read(),v=read();
		if(v==0){a[++len]=Vec(x,y);continue;}
		if(x<v)a[++len]=Vec(0,min(y+v-x,LIM)),a[++len]=Vec(0,max(y-(v-x),0));
		else a[++len]=Vec(x-v,y);
		if(y<v)a[++len]=Vec(min(x+v-y,LIM),0),a[++len]=Vec(max(x-(v-y),0),0);
		else a[++len]=Vec(x,y-v);
		if(x+v>LIM)
		{
			int r=v-(LIM-x);
			a[++len]=Vec(LIM,min(y+r,LIM)),a[++len]=Vec(LIM,max(y-r,0));
		}
		else a[++len]=Vec(x+v,y);
		if(y+v>LIM)
		{
			int r=v-(LIM-y);
			a[++len]=Vec(min(x+r,LIM),LIM),a[++len]=Vec(max(x-r,0),LIM);
		}
		else a[++len]=Vec(x,y+v);
	}
	//fprintf(stderr,"PreWorkCost: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
	//fprintf(stderr,"Len=%d\n",len);
	Vec O(LIM,LIM);
	for(int i=1;i<=len;++i)
		if(a[i].x<O.x)O=a[i];
	for(int i=1;i<=len;++i)v[i]=a[i]-O;
	std::sort(v+1,v+len+1,cmpArg);
	top=0;
	for(int i=1;i<=len;++i)
	{
		while(top>1&&cross(v[i]-b[top],b[top]-b[top-1])<=0)--top;
		b[++top]=v[i];
	}
	for(int i=1;i<=top;++i)b[i]=b[i]+O;
	Vec x=b[1],y=b[2],z=b[3];
	double res=get_circle(x,y,z);
	fprintf(stderr,"res=%.5lf\n",res);
	for(int i=1;i<=top;++i)
	{
		Vec vx=b[i],vy=b[(i+1-1)%top+1],vz=b[(i+2-1)%top+1];
		double f=get_circle(vx,vy,vz);
		if(f>res)res=f,x=vx,y=vy,z=vz;
	}
	printf("%.0lf %.0lf\n%.0lf %.0lf\n%.0lf %.0lf\n",x.x,x.y,y.x,y.y,z.x,z.y);
	return 0;
}