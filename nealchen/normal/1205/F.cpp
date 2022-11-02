#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
int f[101][4951], ans[100];
std::vector<int> xi, he;
std::pair<int, int> g[101][4951];
void extract(int n, int k) {
	if(k==0) return;
	he.push_back(f[n][k]);
	extract(n-f[n][k]+1, k-f[n][k]*(f[n][k]-1)/2);
}
void answer(int n) {
	int ans[101], *pos=ans, l=1, r=n, side=0;
	for(; !xi.empty(); xi.pop_back()) {
		int d=xi.back();
		if(d%2) {
			for(int i=1; i<d/2; ++i) *pos++=r-(d/2-i)*2+1;
			*pos++=l++;
			for(int i=1; i<=d/2; ++i) *pos++=r-(d/2-i)*2;
			r-=d-2;
		} else {
			for(int i=1; i<d/2; ++i) *pos++=l+i*2-1;
			*pos++=r--;
			for(int i=1; i<d/2; ++i) *pos++=l+i*2-2;
			l+=d-2;
		}
	}
	for(; !he.empty(); he.pop_back(), side^=1) {
		int d=he.back();
		if(side) {
			for(int i=1; i<d; ++i) *pos++=l++;
		} else {
			for(int i=1; i<d; ++i) *pos++=r--;
		}
	}
	*pos++=l;
	for(int i=0; i<n; ++i) printf("%d ", ans[i]);
	puts("");
}
int main() {
	int q, n, k;
	f[1][0]=-1;
	for(int i=1; i<=100; ++i)
		for(int j=0; j<=4950; ++j)
			if(f[i][j])
				for(int l=2; i+l<=101; ++l) f[i+l-1][j+l*(l-1)/2]=l;
	for(int j=0; j<=4950; ++j)
		for(int i=1; i<=100; ++i)
			if(f[i][j]) {
				for(int l=1; i+3*l<=100; ++l) g[i+3*l][j+l]=std::make_pair(l, 0);
				break;
			}
	for(int i=4; i<100; ++i)
		for(int j=0; j<=4950; ++j)
			if(g[i][j].first) {
				g[i+1][j]=g[i][j];
				++g[i+1][j].second;
			}
	assert(scanf("%d", &q)==1);
	while(q--) {
		assert(scanf("%d%d", &n, &k)==2);
		k-=n;
		if(k<0) puts("NO"); else if(f[n][k]) {
			puts("YES");
			extract(n, k);
			answer(n);
		} else if(g[n][k].first) {
			puts("YES");
			for(int i=1; i<=g[n][k].first; ++i) xi.push_back(4);
			xi[0]+=g[n][k].second;
			extract(n-g[n][k].first*3-g[n][k].second, k-g[n][k].first);
			answer(n);
		} else puts("NO");
	}
	return 0;
}