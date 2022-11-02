#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;

struct Vector {
	double x, y;
	Vector &operator+=(const Vector &o) {x+=o.x; y+=o.y; return *this;}
	Vector &operator-=(const Vector &o) {x-=o.x; y-=o.y; return *this;}
	Vector &operator*=(double k) {x*=k; y*=k; return *this;}
	Vector &operator/=(double k) {x/=k; y/=k; return *this;}
};
typedef Vector Point;
Vector operator-(const Vector &u) {return {-u.x, -u.y};}
Vector operator+(Vector u, const Vector &v) {return u+=v;}
Vector operator-(Vector u, const Vector &v) {return u-=v;}
Vector operator*(Vector u, double k) {return u*=k;}
Vector operator*(double k, Vector u) {return u*=k;}
Vector operator/(Vector u, double k) {return u/=k;}
bool operator==(const Vector &u, const Vector &v) {return u.x==v.x&&u.y==v.y;}
bool operator!=(const Vector &u, const Vector &v) {return !(u==v);}
double dot(const Vector &u, const Vector &v) {return u.x*v.x+u.y*v.y;}
double cross(const Vector &u, const Vector &v) {return u.x*v.y-u.y*v.x;}

struct Line {
	double A, B, C;
	Vector n() const {return {A, B};}
	double operator()(const Point &P) const {return A*P.x+B*P.y+C;}
	Line unit() const {
		double l=sqrt(A*A+B*B);
		return {A/l, B/l, C/l};
	}
};
typedef Line SemiPlane;
Point operator&(const Line &m, const Line &n) {
	Vector a={m.A, n.A}, b={m.B, n.B}, c={-m.C, -n.C};
	return (Point){cross(c, b), cross(a, c)}/cross(a, b);
}
SemiPlane left(const Point &A, const Point &B) {
	return (SemiPlane){A.y-B.y, B.x-A.x, cross(A, B)}.unit();
}
bool operator<(const Line &m, const Line &n) {
	return m.A==n.A&&m.B==n.B?m.C<n.C:atan2(m.B, m.A)<atan2(n.B, n.A);
}

const int N=300;
int n, ref[N], right[2*N];
bool alive[2*N];
Point p[N], cho[N], cho1, cho2, pos[2*N];
SemiPlane l[2*N], deque[2*N];
std::pair<SemiPlane, int> sort[2*N];
bool check(double radius) {
	for(int k=0; k<n; ++k) {
		SemiPlane m=left(p[k], p[(k+1)%n]);
		sort[k]={m, -1};
		sort[k+n]={{-m.A, -m.B, radius-m.C}, k};
	}
	std::sort(sort, sort+2*n);
	memset(alive, 0, 2*n);
	for(int i=0; i<2*n; ++i) {
		int id=sort[i].second;
		l[i]=sort[i].first;
		if(id!=-1) ref[id]=i; else alive[i]=true;
	}
	for(int i=0, j=0; i<n; ++i) {
		for(int k=i; k<j; ++k) alive[ref[k%n]]=true;
		for(; j<i+n; ++j) {
			int head=0, tail=0;
			alive[ref[j%n]]=true;
			for(int k=0; k<2*n; ++k)
				if(alive[k]&&(head==tail||deque[tail-1].n()!=l[k].n())) {
					while(tail-head>1&&l[k](pos[tail-2])<=0) --tail;
					while(tail-head>1&&l[k](pos[head])<=0) ++head;
					deque[tail++]=l[k];
					if(tail-head>=2) {
						if(deque[tail-2].n()==-deque[tail-1].n()) {
							head=tail;
							break;
						}
						pos[tail-2]=deque[tail-2]&deque[tail-1];
					}
				}
			while(tail-head>1&&deque[head](pos[tail-2])<=0) --tail;
			while(tail-head>1&&deque[tail-1](pos[head])<=0) ++head;
			if(tail-head<3) break;
			cho[i]=pos[head];
		}
		for(int k=i; k<j; ++k) alive[ref[k%n]]=false;
		right[i]=j;
		right[i+n]=j+n;
	}
	for(int i=0; i<n; ++i)
		if(right[right[i]]>=i+n) {
			cho1=cho[i];
			cho2=cho[right[i]%n];
			return true;
		}
	return false;
}
int main() {
	n=rd();
	for(int i=0; i<n; ++i) p[i].x=rd(), p[i].y=rd();
	double l=0, r=30000;
	while(r-l>1e-9) {
		double mid=(l+r)/2;
		(check(mid)?r:l)=mid;
	}
	printf("%.12f\n%.12f %.12f\n%.12f %.12f\n", r, cho1.x, cho1.y, cho2.x, cho2.y);
	return 0;
}