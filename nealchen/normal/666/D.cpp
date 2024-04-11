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

struct Point {
	int x, y;
	bool operator<(const Point &o) const {return x<o.x||(x==o.x&&y<o.y);}
};
void work() {
	int hub[4];
	u32 ans=-1;
	Point loc[4], choice[4];
	for(int i=0; i<4; ++i) loc[i]={rd(), rd()}, hub[i]=i;
	do {
		Point p[4];
		for(int i=0; i<4; ++i) p[i]=loc[hub[i]];
		for(int i=0; i<2; ++i) {
			//four x
			if(p[0].x==p[1].x&&p[1].x!=p[2].x&&p[2].x==p[3].x) {
				int l=p[2].x-p[0].x, a[4]={p[0].y-l, p[1].y, p[2].y-l, p[3].y};
				std::sort(a, a+4);
				if(cmin(ans, (a[3]-a[0]+1)/2)) {
					int y=(a[0]+a[3])/2;
					choice[hub[0]]={p[0].x, y+l};
					choice[hub[1]]={p[1].x, y};
					choice[hub[2]]={p[2].x, y+l};
					choice[hub[3]]={p[3].x, y};
					if(i) for(auto &q: choice) std::swap(q.x, q.y);
				}
			}
			//three x
			if(p[0].x==p[1].x&&p[1].x!=p[2].x) {
				int l=abs(p[2].x-p[0].x), a[4]={abs(p[3].y+l-p[0].y), abs(p[3].y-p[1].y), abs(p[3].y+l-p[2].y), abs(p[2].x-p[3].x)};
				if(cmin(ans, *std::max_element(a, a+4))) {
					choice[hub[0]]={p[0].x, p[3].y+l};
					choice[hub[1]]={p[1].x, p[3].y};
					choice[hub[2]]={p[2].x, p[3].y+l};
					choice[hub[3]]={p[2].x, p[3].y};
					if(i) for(auto &q: choice) std::swap(q.x, q.y);
				}
				a[0]=abs(p[3].y-l-p[0].y), a[2]=abs(p[3].y-l-p[2].y);
				if(cmin(ans, *std::max_element(a, a+4))) {
					choice[hub[0]]={p[0].x, p[3].y-l};
					choice[hub[1]]={p[1].x, p[3].y};
					choice[hub[2]]={p[2].x, p[3].y-l};
					choice[hub[3]]={p[2].x, p[3].y};
					if(i) for(auto &q: choice) std::swap(q.x, q.y);
				}
			}
			//two x
			if(p[2].y!=p[3].y) {
				int l=abs(p[3].y-p[2].y);
				if(p[0].x==p[1].x) { //x-duplicated
					int a[4]={abs(p[2].y-p[0].y), abs(p[3].y-p[1].y), abs(p[0].x+l-p[2].x), abs(p[0].x+l-p[3].x)};
					if(cmin(ans, *std::max_element(a, a+4))) {
						choice[hub[0]]={p[0].x, p[2].y};
						choice[hub[1]]={p[1].x, p[3].y};
						choice[hub[2]]={p[0].x+l, p[2].y};
						choice[hub[3]]={p[0].x+l, p[3].y};
						if(i) for(auto &q: choice) std::swap(q.x, q.y);
					}
					a[2]=abs(p[0].x-l-p[2].x), a[3]=abs(p[0].x-l-p[3].x);
					if(cmin(ans, *std::max_element(a, a+4))) {
						choice[hub[0]]={p[0].x, p[2].y};
						choice[hub[1]]={p[1].x, p[3].y};
						choice[hub[2]]={p[0].x-l, p[2].y};
						choice[hub[3]]={p[0].x-l, p[3].y};
						if(i) for(auto &q: choice) std::swap(q.x, q.y);
					}
				} else if(abs(p[1].x-p[0].x)==l) { //non-duplicated
					int a[4]={abs(p[3].y-p[0].y), abs(p[2].y-p[1].y), abs(p[0].x-p[2].x), abs(p[1].x-p[3].x)};
					if(cmin(ans, *std::max_element(a, a+4))) {
						choice[hub[0]]={p[0].x, p[3].y};
						choice[hub[1]]={p[1].x, p[2].y};
						choice[hub[2]]={p[0].x, p[2].y};
						choice[hub[3]]={p[1].x, p[3].y};
						if(i) for(auto &q: choice) std::swap(q.x, q.y);
					}
				}
			}
			for(auto &q: p) std::swap(q.x, q.y);
		}
	} while(std::next_permutation(hub, hub+4));
	printf("%d\n", ans);
	if(ans!=-1) 
		for(auto q: choice)
			printf("%d %d\n", q.x, q.y);
}
int main() {
	int t=rd();
	while(t--) work();
	return 0;
}