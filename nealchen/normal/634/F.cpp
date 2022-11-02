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

struct Point {
	int x, y;
	Point *prev, *next;
	bool operator<(const Point &o) const {return y<o.y;}
};
int k;
s64 cur;
Point p[3011];
std::vector<Point *> row[3001];
std::vector<std::pair<Point **, Point *>> stack;
void rm(Point *o) {
	Point *q=o, *r=o;
	for(int i=1; i<=k; ++i) r=r->next;
	for(int i=0; i<k&&q!=p; ++i) {
		cur-=(s64)(q->y-q->prev->y)*(r->y-r->prev->y);
		q=q->prev;
		r=r->prev;
	}
	q=o->prev, r=o->next;
	stack.emplace_back(&q->next, q->next);
	stack.emplace_back(&r->prev, r->prev);
	q->next=r, r->prev=q;
}
int main() {
	int r, c, n;
	s64 ans=0;
	r=rd(), c=rd(), n=rd(), k=rd();
	for(int i=1; i<=n; ++i) p[i]={rd(), rd()};
	std::sort(p+1, p+n+1);
	p[0].y=0;
	for(int i=1; i<=n; ++i) row[p[i].x].push_back(p+i);
	for(int i=n+1; i<=n+k; ++i) p[i].y=c+1;
	for(int i=1; i<=n+k; ++i) {
		p[i-1].next=p+i;
		p[i].prev=p+i-1;
	}
	for(int i=0; i<n; ++i) cur+=(p[i+1].y-p[i].y)*(c+1ll-p[i+k].y);
	for(int u=1; u<=r; ++u) {
		int mem=stack.size();
		s64 old=cur;
		for(int d=r; d>=u; --d) {
			ans+=cur;
			for(auto p: row[d]) rm(p);
		}
		while(stack.size()>mem) {
			auto p=stack.back();
			stack.pop_back();
			*(p.first)=p.second;
		}
		cur=old;
		for(auto p: row[u]) rm(p);
	}
	printf("%lld\n", ans);
	return 0;
}