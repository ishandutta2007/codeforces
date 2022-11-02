#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
inline bool cmin(auto &a, const auto &b) {return b<a?(a=b, true):false;}
inline bool cmax(auto &a, const auto &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;

struct Vector {
	long long x, y;
	Vector operator-=(const Vector &o) {x-=o.x; y-=o.y; return *this;}
};
Vector operator-(const Vector &u, const Vector &v) {return {u.x-v.x, u.y-v.y};}
long long times(const Vector &u, const Vector &v) {return u.x*v.y-u.y*v.x;}

typedef unsigned u32;
typedef unsigned long long u64;
const u32 P=1e9+7;
u32 inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
u32 dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
u32 sum(u32 a, u32 b) {return inc(a, b);}
u32 dif(u32 a, u32 b) {return dec(a, b);}
u32 regular(long long x) {return (x%=P)<0?x+P:x;}
struct ModVector {
	u32 x, y;
	ModVector operator+=(const ModVector &o) {inc(x, o.x); inc(y, o.y); return *this;}
	ModVector operator-=(const ModVector &o) {dec(x, o.x); dec(y, o.y); return *this;}
	ModVector operator*=(u64 k) {x=x*k%P; y=y*k%P; return *this;}
};
ModVector regular(const Vector &v) {return {regular(v.x), regular(v.y)};}
ModVector operator+(ModVector u, const ModVector &v) {return u+=v;}
ModVector operator-(ModVector u, const ModVector &v) {return u-=v;}
ModVector operator*(ModVector u, u64 k) {return u*=k;}
ModVector operator*(u64 k, ModVector u) {return u*=k;}
u32 times(const ModVector &u, const ModVector &v) {return ((u64)u.x*v.y+(u64)(P-u.y)*v.x)%P;}

const int N=5e5;
u32 s1[N*2], t1[N*2];
Vector p[N];
ModVector q[N], s2[N*2], t2[N*2];
int main() {
	int n=rd();
	u32 tot=0, ans=0;
	double area=0, cur=0;
	for(int i=0; i<n; ++i) {
		p[i]={rd(), rd()};
		q[i]=regular(p[i]);
	}
	for(int i=1; i<2*n; ++i) {
		ModVector A=q[(i-1)%n], B=q[i%n];
		s1[i]=sum(s1[i-1], times(B, A));
		t1[i]=(t1[i-1]+(u64)i*times(B, A))%P;
		s2[i]=s2[i-1]+B-A;
		t2[i]=t2[i-1]+i*(B-A);
	}
	for(int i=0; i<n; ++i) {
		area+=times(p[(i+1)%n], p[i]);
		inc(tot, times(q[(i+1)%n], q[i]));
	}
	tot=n*(n-3ll)/2%P*tot%P;
	area/=2;
	for(int i=0, j=1; i<n; ++i) {
		for(; cur<area||j<n&&(cur==area); ++j) cur+=times(p[(j+1)%n]-p[i], p[j%n]-p[i]);
		ans=(ans+(u64)j*dif(s1[j], s1[i])+dif(t1[i], t1[j])+times(q[i], j*(s2[j]-s2[i])+t2[i]-t2[j]))%P;
		cur-=times(p[j%n]-p[i], p[(i+1)%n]-p[i]);
	}
	printf("%u\n", dif(tot, sum(ans, ans)));
	return 0;
}