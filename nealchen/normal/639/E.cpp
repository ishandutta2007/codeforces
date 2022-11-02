#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
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
int (*rd)()=read<int>;

struct Item {
	struct RationLess {
		bool operator()(const Item &a, const Item &b) const {return (s64)a.t*b.p<(s64)b.t*a.p;}
	};
	int p, t;
	s64 min, max;
	bool operator<(const Item &o) const {return p<o.p;}
};
const int N=1.5e5;
Item item[N];
int main() {
	int n=rd();
	for(int i=0; i<n; ++i) item[i].p=rd();
	for(int i=0; i<n; ++i) item[i].t=rd();
	std::sort(item, item+n, Item::RationLess());
	s64 sum=0;
	for(int l=0, r=0; l<n; l=r) {
		while(r<n&&(s64)item[l].p*item[r].t==(s64)item[r].p*item[l].t) ++r;
		for(int i=l; i<r; ++i) item[i].min=sum+item[i].t;
		for(int i=l; i<r; ++i) sum+=item[i].t;
		for(int i=l; i<r; ++i) item[i].max=sum;
	}
	std::sort(item, item+n);
	int m=0;
	for(int l=0, r=0; l<n; l=r) {
		while(r<n&&item[l].p==item[r].p) ++r;
		s64 min=item[l].min, max=item[l].max;
		for(int i=l; i<r; ++i) cmin(min, item[i].min);
		for(int i=l; i<r; ++i) cmax(max, item[i].max);
		item[m++]=(Item){item[l].p, item[l].t, min, max};
	}
	double c=1;
	for(int i=1; i<m; ++i) {
		double den=item[i].p*item[i].max-item[i-1].p*item[i-1].min;
		if(den>0) cmin(c, 1.0*sum*(item[i].p-item[i-1].p)/den);
	}
	printf("%.12f\n", c);
	return 0;
}