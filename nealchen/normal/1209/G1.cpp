#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
struct Segment {
	int l, r, n;
	bool operator<(const Segment &o) const {return l<o.l||l==o.l&&r<o.r;}
};
typedef std::pair<int, int> Pair;
const int N=2e5+5;
int n, q, a[N], first[N], last[N], cnt[N];
std::vector<Segment> seg;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
int main() {
	int (*rd)()=read<int>;
	n=rd(), q=rd();
	std::generate(a, a+n, rd);
	for(int i=0; i<n; ++i) ++cnt[a[i]];
	for(int i=1; i<=2e5; ++i) first[i]=n;
	for(int i=n; i--; ) first[a[i]]=i;
	for(int i=1; i<=2e5; ++i) last[i]=-1;
	for(int i=0; i<n; ++i) last[a[i]]=i;
	for(int i=1; i<=2e5; ++i) if(cnt[i]) seg.push_back({first[i], last[i], cnt[i]});
	std::sort(seg.begin(), seg.end());
	int ans=n;
	for(int i=0, j=0, r; i<seg.size(); i=j) {
		for(int r=seg[i].r; ++j<seg.size()&&seg[j].l<r; ) cmax(r, seg[j].r);
		std::sort(seg.begin()+i, seg.begin()+j, [](const Segment &a, const Segment &b) {return a.n>b.n;});
		ans-=seg[i].n;
	}
	printf("%d\n", ans);
	return 0;
}