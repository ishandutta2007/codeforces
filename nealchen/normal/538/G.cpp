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

typedef long long s64;
struct Tri {
	s64 p, t, x, y;
	bool operator<(const Tri &o) const {return t<o.t;}
};
const int N=2e5+2, L=2e6+1;
const s64 INF=4e18;
Tri a[N];
char ans[L];
void gg() {
	puts("NO");
	exit(0);
}
s64 dceil(s64 a, s64 b) {
	if(a<0) return a/b; else return (a+b-1)/b;
}
s64 dfloor(s64 a, s64 b) {
	if(a>0) return a/b; else return (a-b+1)/b;
}
int main() {
	int n=rd(), l=rd();
	auto rdll=read<s64>;
	s64 smin=-INF, smax=INF, dmin=-INF, dmax=INF, s, d, x, y;
	for(int i=1; i<=n; ++i) {
		s64 t=rdll(), x=rdll(), y=rdll();
		a[i]={t/l, t%l, x, y};
		if((t^x^y)&1) gg();
	}
	std::sort(a+1, a+n+1);
	for(int i=0, j=n; i<=n; j=i++) {
		s64 p=a[i].p-a[j].p, t=a[i].t-a[j].t, x=a[i].x-a[j].x, y=a[i].y-a[j].y;
		if(i==0) --p, t+=l;
		if(p==0) {
			if(llabs(x)+llabs(y)>t) gg();
			continue;
		}
		if(p<0) p=-p, x=-x, y=-y;
		cmax(smin, dceil(x+y-t, p));
		cmin(smax, dfloor(x+y+t, p));
		cmax(dmin, dceil(x-y-t, p));
		cmin(dmax, dfloor(x-y+t, p));
	}
	if(smin>smax||dmin>dmax) gg();
	s=smin, d=dmin;
	if((s^l)&1) if(smin!=smax) ++s; else gg();
	if((d^l)&1) if(dmin!=dmax) ++d; else gg();
	x=(s+d)/2, y=(s-d)/2;
	for(int i=0; i<=n; ++i) a[i].x-=x*a[i].p, a[i].y-=y*a[i].p;
	a[n+1]={0, l, x, y};
	for(int i=1, j=0; i<=n+1; ++i) {
		for(s64 k=a[i-1].x; k<a[i].x; ++k) ans[j++]='R';
		for(s64 k=a[i-1].x; k>a[i].x; --k) ans[j++]='L';
		for(s64 k=a[i-1].y; k<a[i].y; ++k) ans[j++]='U';
		for(s64 k=a[i-1].y; k>a[i].y; --k) ans[j++]='D';
		while(j<a[i].t) ans[j++]='L', ans[j++]='R';
	}
	ans[l]=0;
	puts(ans);
	return 0;
}