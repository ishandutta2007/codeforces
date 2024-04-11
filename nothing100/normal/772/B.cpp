#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define PER(i,a,b)for(int i=(b)-1,i##_end_=(a);i>=i##_end_;--i)
#define pb push_back
#define fi first
#define se second
template<class T>inline bool umx(T& A,const T& B){return A<B?A=B,1:0;}
template<class T>inline bool umn(T& A,const T& B){return A>B?A=B,1:0;}
typedef long long LL;
typedef double db;
typedef pair<int,int> PII;
typedef pair<db,int> PDI;

const db pi=acos(-1.);
const db eps=1e-8;
inline db sqr(db x){return x*x;}
inline int dcmp(db x){return x<-eps ? -1 : x>eps;}
inline db stdang(db t){
	while(t<0)t+=2*pi;
	while(t>=2*pi)t-=2*pi;
	return t;
}
// =============== point =============== 
struct point{
	db x,y;
	
	point(){}
	point(const db&x,const db&y):x(x),y(y){}
	// opt
	point operator+(const point&b)const{return point(x+b.x,y+b.y);}
	point operator-(const point&b)const{return point(x-b.x,y-b.y);}
	point operator*(const db&b)   const{return point(x*b,y*b);}
	point operator/(const db&b)   const{return point(x/b,y/b);}
	db    operator%(const point&b)const{return x*b.x+y*b.y;}
	db    operator*(const point&b)const{return x*b.y-y*b.x;}
	bool  operator<(const point&b)const{
		return dcmp(x-b.x)<0||(dcmp(x-b.x)==0&&dcmp(y-b.y)<0);
	}
	bool operator==(const point&b)const{
		return dcmp(x-b.x)==0&&dcmp(y-b.y)==0;
	}
	
	// func
	db len()const{return sqrt(sqr(x)+sqr(y));}
	db len2()const{return sqr(x)+sqr(y);}
	point unit(){return *this/len();}
	point rot(double t){
		return point(cos(t)*x-sin(t)*y,sin(t)*x+cos(t)*y);
	}
	point rot(double cost,double sint){
		return point(cost*x-sint*y,sint*x+cost*y);
	}
	db ang(){return stdang(atan2(y,x));}
	// scan/print
	void scan(){
		double x,y;scanf("%lf%lf",&x,&y);
		this->x=x,this->y=y;
	}
	void print(){
		double x=this->x,y=this->y;
		printf("(%lf,%lf)\n",x,y);
	}
};
db area(const point&a,const point&b,const point&c){return (c-a)*(b-a)/2.;}

// =============== line beam segment =============== 
struct line{
	point a,b,v;
	
	line(){}
	line(const point&a,const point&b):a(a),b(b){v=b-a;}
	// ax+by+c > 0
	line(db a,db b,db c){
		v=point(b,-a);
		this->a=(fabs(a)>fabs(b)) ? point(-c/a,0.) : point(0.,-c/b);
		this->b=this->a+v;
	}
	point pos(db t)const{return a+v*t;}
	db dis(const point&p)const{return (v*(p-a))/v.len();}		// dis to line // signed
	db projt(const point&p)const{return ((p-a)%v)/(v%v);}
	point proj(const point&p)const{return pos(projt(p));}
	
	point reflect(const point& p)const{return p+(proj(p)-p)*2;}
	line reflect(const line& l)const{return line(reflect(l.a),reflect(l.b));}
	
	int dir(const point&p)const{return dcmp(v*(p-a));}
};

const int maxn=1010;
point p[maxn];
int n;
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	REP(i,0,n)p[i].scan();
	db res=1e30;
	REP(i,0,n){
		point A=p[i],B=p[(i+1)%n],C=p[(i+2)%n];
//		printf("%.3f\n",line(A,C).dis(B));
		umn(res,line(A,C).dis(B));
	}
	printf("%.10f\n",res/2.);
	return 0;
}