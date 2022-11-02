#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;
struct Vector {
	double x, y;
	Vector operator-() const {return {-x, -y};}
	Vector operator+=(const Vector &o) {x+=o.x; y+=o.y; return *this;}
	Vector operator-=(const Vector &o) {x-=o.x; y-=o.y; return *this;}
	Vector operator*=(double k) {x*=k; y*=k; return *this;}
	Vector operator/=(double k) {x/=k; y/=k; return *this;}
};
Vector operator+(const Vector &u, const Vector &v) {return {u.x+v.x, u.y+v.y};}
Vector operator-(const Vector &u, const Vector &v) {return {u.x-v.x, u.y-v.y};}
Vector operator*(const Vector &u, double k) {return {u.x*k, u.y*k};}
Vector operator*(double k, const Vector &u) {return {u.x*k, u.y*k};}
Vector operator/(const Vector &u, double k) {return {u.x/k, u.y/k};}
double cdot(const Vector &u, const Vector &v) {return u.x*v.x+u.y*v.y;}
double times(const Vector &u, const Vector &v) {return u.x*v.y-u.y*v.x;}
double sqr(const Vector &u) {return cdot(u, u);}
double abs(const Vector &u) {return sqrt(sqr(u));}
double cosangle(const Vector &u, const Vector &v) {return cdot(u, v)/(abs(u)*abs(v));}
typedef Vector Point;
typedef std::vector<Point> PointSet;
PointSet A, B, co;
bool chk(Point P, Point Q) {
	double hi=DBL_MAX, lo=-DBL_MAX;
	Point M=(P+Q)/2;
	Vector n={P.y-Q.y, Q.x-P.x};
	for(auto R: A) {
		double u=2*cdot(R-M, n), v=sqr(R-M)-sqr(P-Q)/4; //ut>=v
		if(u==0&&v>0) return false;
		if(u>0) cmax(lo, v/u); //t>=v/u
		if(u<0) cmin(hi, v/u); //t<=v/u
	}
	for(auto R: B) {
		double u=2*cdot(R-M, n), v=sqr(R-M)-sqr(P-Q)/4; //ut<v
		if(u==0&&v<=0) return false;
		if(u>0) cmin(hi, v/u-1e-9); //t<v/u
		if(u<0) cmax(lo, v/u+1e-9); //t>v/u
	}
	return lo<=hi;
}
bool solve(int l, int r) {
	if(chk(co[l], co[r])) return true;
	if(r-l<2) return false;
	int mid;
	double maxcos=-2;
	for(int k=l; ++k<r; ) if(cmax(maxcos, cosangle(co[r]-co[k], co[l]-co[k]))) mid=k;
	return solve(l, mid)||solve(mid, r);
}
bool sol() {
	if(A.size()==1) return true;
	std::sort(A.begin(), A.end(), [](const Vector &u, const Vector &v) {return u.x<v.x||(u.x==v.x&&u.y<v.y);});
	co.clear();
	for(auto P: A) {
		while(co.size()>1&&times(co.back()-co[co.size()-2], P-co.back())>=0) co.pop_back();
		co.push_back(P);
	}
	std::reverse(A.begin(), A.end());
	int m=co.size();
	for(auto P: A) {
		while(co.size()>m&&times(co.back()-co[co.size()-2], P-co.back())>=0) co.pop_back();
		co.push_back(P);
	}
	co.pop_back();
	if(solve(0, co.size()-1)) return true;
	std::swap(A, B);
	return false;
}
int main() {
	int n=rd(), m=rd();
	while(n--) A.push_back({(double)rd(), (double)rd()});
	while(m--) B.push_back({(double)rd(), (double)rd()});
	puts(sol()||sol()?"YES":"NO");
	return 0;
}