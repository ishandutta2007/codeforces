#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
int n, fa[10000], co[10000];
int find(int x) {
	if(x==fa[x]) return x;
	int f=find(fa[x]);
	co[x]^=co[fa[x]];
	return fa[x]=f;
}
int ask(int x1, int y1, int x2, int y2) {
	int res;
	printf("? %d %d %d %d\n", x1+1, y1+1, x2+1, y2+1);
	fflush(stdout);
	scanf("%d", &res);
	return res;
}
int add(int x1, int y1, int x2, int y2, int w) {
	int x=x1*n+y1, y=x2*n+y2, u=find(x), v=find(y);
	fa[u]=v;
	co[u]=w^co[x]^co[y]^1;
}
bool same(int x1, int y1, int x2, int y2) {
	int x=x1*n+y1, y=x2*n+y2;
	find(x), find(y);
	return co[x]==co[y];
}
int col(int x1, int y1) {
	int x=x1*n+y1;
	find(x), find(0);
	return co[x]^co[0]^1;
}
void answer() {
	puts("!");
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) printf("%d", col(i, j));
		puts("");
	}
	fflush(stdout);
	exit(0);
}
int main() {
	scanf("%d", &n);
	for(int i=0; i<n*n; ++i) fa[i]=i;
	for(int i=1; i<n; ++i) for(int j=1; j<n; ++j)
		add(i-1, j-1, i, j, ask(i-1, j-1, i, j));
	for(int i=0; i+2<n; ++i) add(0, i, 0, i+2, ask(0, i, 0, i+2));
	for(int i=1; i<n; ++i) add(i, 0, i, 2, ask(i, 0, i, 2));
	for(int i=0; i+1<n; ++i)
		for(int j=0; j+2<n; ++j)
			if(!same(i+1, j, i, j+1)||!same(i+1, j+1, i, j+2)) {
				add(i, j, i+1, j+2, ask(i, j, i+1, j+2));
				answer();
			}
	for(int i=0; i+2<n; ++i)
		for(int j=0; j+1<n; ++j)
			if(!same(i+1, j, i, j+1)||!same(i+2, j, i+1, j+1)) {
				add(i, j, i+2, j+1, ask(i, j, i+2, j+1));
				answer();
			}
	for(int i=0; i+1<n; ++i)
		for(int j=0; j+2<n; ++j)
			if(same(i, j, i+1, j+1)==same(i, j+1, i+1, j+2)) {
				add(i, j, i+1, j+2, ask(i, j, i+1, j+2));
				answer();
			}
	for(int i=0; i+2<n; ++i)
		for(int j=0; j+1<n; ++j)
			if(same(i, j, i+1, j+1)==same(i+1, j, i+2, j+1)) {
				add(i, j, i+2, j+1, ask(i, j, i+2, j+1));
				answer();
			}
	return 0;
}