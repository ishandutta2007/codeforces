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
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
//const u32 P=;
//u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
//u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
//u32 sum(u32 a, u32 b) {return inc(a, b);}
//u32 dif(u32 a, u32 b) {return dec(a, b);}

struct Point {
	long double x, y;
	Point operator-() const {return (Point){-x, -y};}
	Point operator-(const Point &o) const {return (Point){x-o.x, y-o.y};}
	bool operator<(const Point &o) const {return x<o.x||x==o.x&&y<o.y;}
	Point operator+=(const Point &o) {x+=o.x; y+=o.y; return *this;}
	Point operator-=(const Point &o) {x-=o.x; y-=o.y; return *this;}
};
long double times(const Point &u, const Point &v) {return u.x*v.y-u.y*v.x;}

const int N=2500;
int n;
Point p[N], q[N];
int main() {
	s64 sum=0;
	n=rd();
	for(int i=0; i<n; ++i) p[i]={(long double)rd(), (long double)rd()};
	for(int i=0; i<n; ++i) {
		s64 cnt=-(n-1ll)*(n-2ll)/2*(n-3ll)/3;
		for(int j=0; j<n; ++j) if(i!=j) q[j-(i<j)]=p[j]-p[i];
		int pos=std::partition(q, q+n-1, [](const Point &A) {return A.y>=0;})-q;
		std::sort(q, q+pos, [](const Point &A, const Point &B) {return times(A, B)>0;});
		std::sort(q+pos, q+n-1, [](const Point &A, const Point &B) {return times(A, B)>0;});
		for(int j=0, r=0; j<n-1; ++j) {
			if(r==j) ++r;
			while(times(q[j], q[r%(n-1)])>0) ++r;
			cnt+=(r-j-1ll)*(n-r+j-1ll);
		}
		cnt=cnt/2*(n-4)/2;
		sum+=cnt;
	}
	printf("%lld\n", sum);
	return 0;
}